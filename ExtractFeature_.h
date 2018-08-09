#include <opencv2/opencv.hpp>
//using namespace cv;
using namespace std;

float* ExtractFeature_(cv::Mat FaceROI);//添加一个提取特征的函数
std::vector<float> ExtractFeature(cv::Mat FaceROI);//给一个图片 返回一个vector<float>容器
void Caffe_Predefine();