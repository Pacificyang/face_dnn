#include <opencv2/opencv.hpp>

using namespace std;
//using namespace cv;


cv::Mat FaceProcessing(const cv::Mat &img_, double gamma = 0.2, double sigma0 = 1,
	double sigma1 = -2, double mask = 0, double do_norm = 10);

int gauss(float x[], float y[], int length, float sigma);
cv::Mat gaussianfilter(cv::Mat img, double sigma0, double sigma1, double shift1, double shift2);
double MatMaxMin(cv::Mat im, cv::String flag = "MAX");
cv::Mat gaussianfilter(cv::Mat img, double sigma0, double sigma1, double shift1 = 0, double shift2 = 0);
