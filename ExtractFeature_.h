#include <opencv2/opencv.hpp>
//using namespace cv;
using namespace std;

float* ExtractFeature_(cv::Mat FaceROI);//���һ����ȡ�����ĺ���
std::vector<float> ExtractFeature(cv::Mat FaceROI);//��һ��ͼƬ ����һ��vector<float>����
void Caffe_Predefine();