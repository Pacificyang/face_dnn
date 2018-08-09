#include <opencv.hpp>
#include "SaveVector.h"
//using namespace cv;
using namespace std;

class Register
{
public:
	string FaceSpace;//The name of FaceSpace
	vector<string> FaceName;//People's name ,the same as FaceNumber
							//float *
	float* MatToVector_(cv::Mat TrainMat);//��Mat������ʶ��Ԥ�����ת��Ϊһ������
	float *FaceMatrix[20];//20����
	void JoinFaceSpace_(cv::Mat newFace, string FaceSpace, string FaceName);//join the new face to FaceSpace
	float** LoadVector_(string FaceSpace);//��������
	cv::Mat FaceMatrix_mat;//��ʱ�洢��ȡ��Mat����
private:

	void SaveVector_(float *FaceMatrix_[], vector<string> FaceName_, string FaceSpace_) // save the people's  face vector
	{
		//ʹ��xml���洢����
		if (!(FaceMatrix_ == NULL) && !FaceName_.empty())
		{
			SaveFaceMatrix(FaceMatrix_, "data/" + FaceSpace_ + "_FaceMatrix.xml", FaceName_.size());
			SaveNameVector(FaceName, "data/" + FaceSpace_ + "_NameVector.txt");
		}
		else { cout << "Sorry.There are some problems while saving your face and name. please try again" << endl; }
	}
};
