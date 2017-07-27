#include "opencv.hpp"
#include <iostream>
#include <stdlib.h>

#define Max(a,b,c) a>b? (a>c ? a:c):(b>c? b:c)
#define Min(a, b, c) a < b ? (a < c ? a : c) : (b < c ? b : c)


using namespace cv;

Rect selection;
bool bLButtonDown = false;
typedef enum { INIT, CALC_HIST, TRACKING } STATUS;
STATUS trackingMode = INIT;


float H, S, V;


float RGBtoHSV(unsigned char r, unsigned char g, unsigned char b) {
	float min, max, delta;
	float h; float s; float v;
	h = s = v = 0;
	min = Min(r, g, b);
	max = Max(r, g, b);
	v = max;
	delta = max - min;
	if (max != 0) s = delta / max;
	else {
		s = 0;
		h = -1;
		return 0;
	}
	if (r == max) h = (g - b) / delta;
	else if (g == max) h = 2 + (b - r) / delta;
	else h = 4 + (r - g) / delta;

	h *= 60;
	if (h < 0) h += 360;
	return h;
}

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
	/*
	Mat img = imread("sample.png", 1);
	int count = 0;
	imshow("Fuck", img);


	//이게 원본 RGB
	for (int j = 0;j < img.rows;j = j + 10) {
		for (int i = 0;i < img.cols;i = i + 10) {
			unsigned char b = img.at<unsigned char>(cv::Point(3 * i, j));
			unsigned char g = img.at<unsigned char>(cv::Point(3 * i + 1, j));
			unsigned char r = img.at<unsigned char>(cv::Point(3 * i + 2, j));
			count++;

			printf("%d color value  : %d, %d, %d \n", count, b, g, r);

		}
	}
	Mat result(img.rows,img.cols,CV_32F);

	//이건 img파일을 result파일에 RGB를 HSV로 바꿔서 저장하는 코드
	cvtColor(img, result, CV_BGR2HSV);
	count = 0;
	printf("\n\n\nHSV color\n\n\n");

	//이건 HSV만드는거
	for (int j = 0;j < img.rows;j = j + 10) {
		for (int i = 0;i < img.cols;i = i + 10) {
			unsigned char b = img.at<unsigned char>(cv::Point(3 * i, j));
			unsigned char g = img.at<unsigned char>(cv::Point(3 * i + 1, j));
			unsigned char r = img.at<unsigned char>(cv::Point(3 * i + 2, j));
			count++;
			
			printf("%d color value  :  H=%f \n", count,result.at<float>(Point(j,i)));

		}
	}
	

	imshow("FuckFuck", result);

	waitKey(0);
	destroyAllWindows();
	*/

	VideoCapture inputVideo("testvideo.mp4");

	if (!inputVideo.isOpened())
	{
		printf("Can not open \n\n");
		return 0;
	}
	Size size = Size((int)inputVideo.get(CAP_PROP_FRAME_WIDTH), (int)inputVideo.get(CAP_PROP_FRAME_HEIGHT));
	int fps = (int)inputVideo.get(CAP_PROP_FPS);
	if (fps == 0)fps = 24;
	
	Mat dstImage;
	
	namedWindow("dstImage");
	setMouseCallback("dstImage", onMouse, (void *)&dstImage);
	//
	////여기부터 내 테스트 환경
	//Mat test;
	//int delay = 1000 / fps;
	//
	//inputVideo >> test;
	//Mat hsv_test = Mat(test.rows, test.cols,CV_32F);
	//Mat back_test;
	//printf("%d %d", test.rows, test.cols);
	//
	//for (;;) {
	//	inputVideo >> test;
	//
	//	//for (int i = 0;i < test.rows;i++) {
	//	//	for (int j = 0;j < test.cols;j++) {
	//	//		unsigned char b = test.at<unsigned char>(Point(3 * j, i));
	//	//		unsigned char g = test.at<unsigned char>(Point(3 * j+ 1, i));
	//	//		unsigned char r = test.at<unsigned char>(Point(3 * j + 2, i));
	//	//		//hsv_test.at<uchar>(Point(3 * i, j)) = 12;
	//	//		//hsv_test.at<uchar>(Point(3 * i+1, j)) = 1;
	//	//		//hsv_test.at<uchar>(Point(3 * i+2, j)) = 128;
	//	//		hsv_test.at<float>(Point(j, i)) = RGBtoHSV(r, g, b)/(r+g+b);
	//	//	}
	//	//}
	//	
	//	cvtColor(test, hsv_test, CV_RGB2HSV);
	//	back_test &= hsv_test;
	//	bitwise_and(back_test, hsv_test, back_test);
	//	imshow("Fucking", test);
	//	imshow("SuperFuck", hsv_test);
	//	imshow("FFFFFFFFuck", back_test);
	//
	//	int ckey = waitKey(delay);
	//	if (ckey == 27) break;  //esc누르면 종료
	//}


	
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
		inputVideo >> frame;  //inputVideo를 frame에 우선 저장
		if (frame.empty())  //frame이 비어있다면 break!!
			break;
		cvtColor(frame, hsvImage, CV_BGR2HSV);  //frame의 RGV를 HSV로 바꿔주는 코드인듯??
		frame.copyTo(dstImage); //dstImage를 복사함 dstImage는 지금 HSV??
		
		//마우스포인트가 있다면 ??    dstROI에 dstImage 중 선택된 애들을 저장
		if (bLButtonDown && 0 < selection.width && 0 < selection.height)
		{
			Mat dstROI = dstImage(selection);
			bitwise_xor(dstROI, Scalar::all(255), dstROI);   //xor 연산자를 해줘야 드래그할때 네모가 보인다.
		}
		//추적모드

		if (trackingMode) {
			int vmin = 50, vmax = 256, smin = 50;
		
			inRange(hsvImage, Scalar(0, smin, MIN(vmin, vmax)), Scalar(180, 256, MAX(vmin, vmax)), mask);
			
//			imshow("mask", mask);

			int ch[] = { 0,0 };
			hImage.create(hsvImage.size(), CV_8U);  //CV_8U는 unsigned integer
			
			
			mixChannels(&hsvImage, 1, &hImage, 1, ch, 1);
//			imshow("hImage", hImage);

			if (trackingMode == CALC_HIST) {
				Mat hImageROI(hImage, selection), maskROI(mask, selection);
				calcHist(&hImageROI, 1, &channels, maskROI, hist, 1, &histSize, ranges); //이것도 만들어야댐 
				normalize(hist, hist, 0, 255, NORM_MINMAX); //정규화 이거도 만들어야댐...
				trackWindow = selection;
				trackingMode = TRACKING;
			}

			calcBackProject(&hImage, 1, &channels, hist, backProject, ranges);
			backProject &= mask;
			bitwise_and(backProject, mask, backProject);
//			imshow("backProject", backProject);
			
			meanShift(backProject, trackWindow, criteria);

			Point pt1 = Point(trackWindow.x, trackWindow.y);
			Point pt2 = Point(pt1.x + trackWindow.width, pt1.y + trackWindow.height);
			rectangle(dstImage, pt1, pt2, Scalar(0, 0, 255), 2);
		}

		imshow("dstImage", dstImage);
		
		outputVideo << dstImage;
		int ckey = waitKey(delay);
		if (ckey == 27) break;  //esc누르면 종료
	}
	
	return 0;
}


