#include <opencv.hpp>
using namespace std;

class Recognition
{
public:

	vector<string> NameVector;

	//vector
	void LoadVector(string FaceSpace);//��������,���������ΪFaceSpace_FaceVector/FaceSpace_FaceName
	void LoadRecognitionModel(vector<vector<float>> FaceMatrix, vector<string> NameVector);//����ʶ��ģ�ͣ���Ҫ����FaceMarix��NameVector.
	string Predict(cv::Mat LoadGetFace);//Ԥ��
									//�÷��� Recognition test; test.LoadRecognitionModel();cout<<test->predict(Mat) ; test.update()
	void clear();
	void update(vector<vector<float>> FaceMatrix, vector<string> NameVector);//change .
	vector<vector<float>> FaceMat;

	//pacificy add
	void JoinFaceSpace(cv::Mat newFace, string FaceSpace, string FaceName);
	vector<float> MatToVector(cv::Mat TrainMat);//��Mat������ʶ��Ԥ�����ת��Ϊһ������
	void Recognition::SaveVector(vector<vector<float>> FaceMatrix_, vector<string> FaceName_, string FaceSpace_);
	//string Recognition::Recomend(cv::Mat LoadGetFace);

private:
	vector <vector<float>> ReadVector(string FaceSpace);//input FaceSpace ,read to get vector <vector<float>>

};