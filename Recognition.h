#include <opencv.hpp>
using namespace std;

class Recognition
{
public:

	vector<string> NameVector;

	//vector
	void LoadVector(string FaceSpace);//读入数据,保存的名称为FaceSpace_FaceVector/FaceSpace_FaceName
	void LoadRecognitionModel(vector<vector<float>> FaceMatrix, vector<string> NameVector);//创建识别模型，需要输入FaceMarix，NameVector.
	string Predict(cv::Mat LoadGetFace);//预测
									//用法： Recognition test; test.LoadRecognitionModel();cout<<test->predict(Mat) ; test.update()
	void clear();
	void update(vector<vector<float>> FaceMatrix, vector<string> NameVector);//change .
	vector<vector<float>> FaceMat;

	//pacificy add
	void JoinFaceSpace(cv::Mat newFace, string FaceSpace, string FaceName);
	vector<float> MatToVector(cv::Mat TrainMat);//将Mat在人脸识别、预处理后转换为一个向量
	void Recognition::SaveVector(vector<vector<float>> FaceMatrix_, vector<string> FaceName_, string FaceSpace_);
	//string Recognition::Recomend(cv::Mat LoadGetFace);

private:
	vector <vector<float>> ReadVector(string FaceSpace);//input FaceSpace ,read to get vector <vector<float>>

};