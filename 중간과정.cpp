#include "opencv.hpp"
#include <math.h>

using namespace cv;
using namespace std;

void on_mouse(int event, int x, int y, int flags, void* param);
double* mycal(Mat src, Mat dst);
unsigned int Ix(Mat src, int i, int j);
double** calcBack(Mat src, double *inputHist, double *modelHist);

int main()
{
	Mat srcImg, srcImg2;
	Mat dstImg, dstImg2;
	Mat white, white2;

	VideoCapture inputVideo("test.wmv");
	Mat frame;
	int fps = (int)inputVideo.get(CAP_PROP_FPS);
	if (fps == 0)fps = 24;

	double *inputHist;
	double *modelHist;

	srcImg = imread("Lenna3.png");
	if (srcImg.empty())
		return -1;
	srcImg2 = cv::imread("white.png");
	if (srcImg2.empty())
		return -1;
	white = imread("white.png");
	if (white.empty())
		return -1;
	white2 = imread("white.png");
	if (white2.empty())
		return -1;

	resize(white, dstImg, srcImg.size(), 0, 0);
	resize(white2, dstImg2, srcImg2.size(), 0, 0);




	cv::namedWindow("Source Image");
	cv::namedWindow("Result Image");
	cv::namedWindow("Source Image2");
	cv::namedWindow("Result Image2");

	setMouseCallback("Source Image", on_mouse);
	setMouseCallback("Result Image", on_mouse);
	setMouseCallback("Source Image2", on_mouse);
	setMouseCallback("Result Image2", on_mouse);


	for (;;) {
		inputVideo
		modelHist = mycal(srcImg, dstImg);
		inputHist = mycal(srcImg2, dstImg2);

		double **w;

		w = calcBack(srcImg2, inputHist, modelHist);

		double sx = 0, sy = 0, sum = 0;
		for (int i = 0;i < srcImg.rows;i++) {
			for (int j = 0;j < srcImg.cols;j++) {
				sum += w[i][j];
				sx += w[i][j] * j;
				sy += w[i][j] * i;
			}
		}
		double new_x, new_y;
		new_x = sx / sum;
		new_y = sy / sum;

		printf("(%.lf,%.lf)", new_x, new_y);
		circle(srcImg, Point(new_x, new_y), 2, 0, 1, 8, 0);

	}
	while (1)
	{
		imshow("Source Image", srcImg);
		imshow("Source Image2", srcImg2);
		imshow("Result Image", dstImg);
		imshow("Result Image2", dstImg2);



		int key = cv::waitKey(10);
		if (key == 27)
			break;
	}

	cv::destroyAllWindows();

	return 0;
}





///////////////////////////////////////////////////////////////

void on_mouse(int event, int x, int y, int flags, void* param) {
	if (event == CV_EVENT_LBUTTONDOWN) {
		printf("Mouse Pointer: %d, %d \n", x, y);
	}
}
double* mycal(Mat src, Mat dst) {
	int i, j;
	unsigned char B, G, R, gray;
	unsigned int arr[256] = { 0, };
	int count = 0;
	double *myA;
	myA = (double*)malloc(sizeof(double) * 256);
	for (i = 0;i<src.rows;i++) {
		for (j = 0;j<src.cols;j++) {
			B = src.at<unsigned char>(Point(3 * j, i));
			G = src.at<unsigned char>(Point(3 * j + 1, i));
			R = src.at<unsigned char>(Point(3 * j + 2, i));
			gray = (299 * R + 587 * G + 114 * B) / 1000;
			arr[gray]++;
			count++;
		}
	}
	for (i = 0;i<=255;i++) {
		myA[i] = (double)arr[i] / (double)count;
		//printf("%lf\n",myA[i]);
	}

	for (i = 0;i <= 255;i++) {
		line(dst, Point(i, dst.rows*(1 - myA[i])), Point(i, dst.rows), cv::Scalar(0, 0, 0), 2);
	}

	return myA;
}

unsigned int Ix(Mat src, int i, int j) {

	unsigned char B, G, R, gray;

	B = src.at<unsigned char>(Point(3 * j, i));
	G = src.at<unsigned char>(Point(3 * j + 1, i));
	R = src.at<unsigned char>(Point(3 * j + 2, i));
	gray = (299 * R + 587 * G + 114 * B) / 1000;
	//printf("%d %d %d %d\n",R,G,B,gray);
	return gray;
}

double** calcBack(Mat src, double *inputHist, double *modelHist) {

	int i, j;
	double **w;
	double h;

	w = (double**)malloc(sizeof(double*)*src.rows);
	for (i = 0;i<src.cols;i++)
		w[i] = (double*)malloc(sizeof(double)*src.cols);

	int count = 0;
	for (i = 0;i<src.rows;i++) {
		for (j = 0;j<src.cols;j++) {
			if (inputHist[Ix(src, i, j)] == 0)
				h = 0;
			else
				h = modelHist[Ix(src, i, j)] / inputHist[Ix(src, i, j)];

			w[i][j] = sqrt(h);
			count++;
		}
	}

	return w;
}
