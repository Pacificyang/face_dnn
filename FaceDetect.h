#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>

#include "facedetect-dll.h"

//#pragma comment(lib,"libfacedetect.lib")
#pragma comment(lib,"libfacedetect-x64.lib")

//define the buffer size. Do not change the size!
#define DETECT_BUFFER_SIZE 0x20000



//using namespace cv;
// define 
cv::Mat Facedetect(cv::Mat frame);
//dlib�����ú��� ���漸�»ὲ
void Dlib_Predefine();