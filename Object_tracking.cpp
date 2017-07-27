#include "opencv.hpp"
#include <algorithm>


using namespace cv;

Rect selection;
bool bLButtonDown = false;
typedef enum { INIT, CALC_HIST, TRACKING } STATUS;
STATUS trackingMode = INIT;

void onMouse(int mevent, int x, int y, int flags, void* param)
{
	static Point origin;
	Mat *pMat = (Mat *)param;
	Mat image = Mat(*pMat);
	if (bLButtonDown) {
		selection.x = MIN(x, origin.x);
		selection.y = MIN(y, origin.y);
		selection.width = selection.x + abs(x - origin.x);
		selection.height = selection.y + abs(y - origin.y);

		selection.x = MAX(selection.x, 0);
		selection.y = MAX(selection.y, 0);
		selection.width = MIN(selection.width, image.cols);
		selection.width -= selection.x;
		selection.height -= selection.y;
	}
	switch (mevent)
	{
	case EVENT_LBUTTONDOWN:
		origin = Point(x, y);
		selection = Rect(x, y, 0, 0);
		bLButtonDown = true;
		break;
	case EVENT_LBUTTONUP:
		bLButtonDown = false;
		if (selection.width>0 && selection.height>0)
			trackingMode = CALC_HIST;
		break;
	}
}

int main()
{
	VideoCapture inputVideo(0);
	
	if (!inputVideo.isOpened())
	{
		printf("Can not open \n\n");
		return 0;
	}
	Size size = Size((int)inputVideo.get(CAP_PROP_FRAME_WIDTH),(int)inputVideo.get(CAP_PROP_FRAME_HEIGHT));
	int fps = (int)inputVideo.get(CAP_PROP_FPS);
	if (fps == 0)fps = 24;

	Mat dstImage;
	namedWindow("dstImage");
	setMouseCallback("dstImage", onMouse, (void *)&dstImage);

	int histSize = 8;
	float valueRange[] = { 0,180 };
	const float* ranges[] = { valueRange };
	int channels = 0;
	Mat hist, backProject;

	int fourcc = VideoWriter::fourcc('d', 'i', 'v', 'x');
	bool isColor = true;
	
	VideoWriter outputVideo("output.avi", fourcc, fps, size, isColor);
	
	if (!outputVideo.isOpened()) {
		printf("Can not open outputVideo!!!\n\n");
		return 0;
	}
	if (fourcc != -1)
	{
		imshow("dstImage", NULL);
		waitKey(100);
	}
	TermCriteria criteria(TermCriteria::COUNT + TermCriteria::EPS, 10, 2);

	Rect trackWindow;
	int delay = 1000 / fps;
	Mat frame, hImage, hsvImage, mask;

	for (;;)
	{
		inputVideo >> frame;
		if (frame.empty())
			break;
		cvtColor(frame, hsvImage, CV_BGR2HSV);
		frame.copyTo(dstImage);
		if (bLButtonDown && 0 < selection.width && 0 < selection.height)
		{
			Mat dstROI = dstImage(selection);
			bitwise_xor(dstROI, Scalar::all(255), dstROI);
		}
		
		if (trackingMode) {
			int vmin = 50, vmax = 256, smin = 50;
			inRange(hsvImage, Scalar(0, smin, MIN(vmin, vmax)), Scalar(180, 256, MAX(vmin, vmax)), mask);
			imshow("mask", mask);

			int ch[] = { 0,0 };
			hImage.create(hsvImage.size(), CV_8U);
			mixChannels(&hsvImage, 1, &hImage, 1, ch, 1);
			imshow("hImage", hImage);
			if (trackingMode == CALC_HIST) {
				Mat hImageROI(hImage, selection), maskROI(mask, selection);
				calcHist(&hImageROI, 1, &channels, maskROI, hist, 1, &histSize, ranges);
				normalize(hist, hist, 0, 255, NORM_MINMAX);
				trackWindow = selection;
				trackingMode = TRACKING;
			}
			calcBackProject(&hImage, 1, &channels, hist, backProject, ranges);
			backProject &= mask;
			bitwise_and(backProject, mask, backProject);
			imshow("backProject", backProject);
			
			meanShift(backProject, trackWindow, criteria);

			Point pt1 = Point(trackWindow.x, trackWindow.y);
			Point pt2 = Point(pt1.x + trackWindow.width, pt1.y + trackWindow.height);
			rectangle(dstImage, pt1, pt2, Scalar(0, 0, 255), 2);
		}

		imshow("dstImage", dstImage);
		
		outputVideo << dstImage;
		int ckey = waitKey(delay);
		if (ckey == 27) break;
	}
	return 0;
}


