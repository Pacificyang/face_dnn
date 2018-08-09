#include <opencv2/opencv.hpp>
#include <fstream>
#include <sstream>
//using namespace cv;
using namespace std;

void SaveNameVector(vector<string>   &NameVector, string filename);//保存姓名，需要输入
vector<string> LoadNameVector(vector<string>   &NameVector, string filename);
void SaveFaceMatrix(float *FaceMatrix[], string filename, int rows);//用于保存提取出来特征的人脸矩阵，需要输入：人脸矩阵、保存的文件名，矩阵的行数（列均为2622维）
cv::Mat LoadMat(string file);//将xml文件提取出来转换为OpenCV的Mat类
float** MatToVector2d(cv::Mat &FaceMatrix_mat);//将Mat类转换为二维数组
vector<vector<float> >  LoadFaceMatrix(string FaceVectorRoad);
float** LoadFaceMat(string FaceVectorRoad);

//pacificy add
//cv::Mat Vector2dToMat_(vector<vector<float>> FaceMatrix, int rows);
void SaveFaceMatrix_(vector<vector<float>> FaceMatrix, string filename, int rows);