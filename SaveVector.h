#include <opencv2/opencv.hpp>
#include <fstream>
#include <sstream>
//using namespace cv;
using namespace std;

void SaveNameVector(vector<string>   &NameVector, string filename);//������������Ҫ����
vector<string> LoadNameVector(vector<string>   &NameVector, string filename);
void SaveFaceMatrix(float *FaceMatrix[], string filename, int rows);//���ڱ�����ȡ��������������������Ҫ���룺�������󡢱�����ļ�����������������о�Ϊ2622ά��
cv::Mat LoadMat(string file);//��xml�ļ���ȡ����ת��ΪOpenCV��Mat��
float** MatToVector2d(cv::Mat &FaceMatrix_mat);//��Mat��ת��Ϊ��ά����
vector<vector<float> >  LoadFaceMatrix(string FaceVectorRoad);
float** LoadFaceMat(string FaceVectorRoad);

//pacificy add
//cv::Mat Vector2dToMat_(vector<vector<float>> FaceMatrix, int rows);
void SaveFaceMatrix_(vector<vector<float>> FaceMatrix, string filename, int rows);