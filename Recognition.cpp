#include "Recognition.h"
#include "SaveVector.h"
#include "ExtractFeature_.h"
#include "FaceDetect.h"
#include "ComputeDistance.h"

void Recognition::LoadVector(string FaceSpace) // save the people's  face vector
{
	string FaceVectorRoad = "data/" + FaceSpace + "_FaceMatrix.xml";
	string NameVectorRoad = "data/" + FaceSpace + "_NameVector.txt";
	vector<vector<float> >  FaceVector;
	FaceVector = LoadFaceMatrix(FaceVectorRoad);
	NameVector = LoadNameVector(NameVector, NameVectorRoad);
	if (!FaceVector.empty() && !NameVector.empty())
	{
		FaceMat = FaceVector;
		NameVector = NameVector;
		cout << "Sucessfully read the FaceSpace:" + FaceSpace + "'s data!" << endl;
	}
	else { cout << "There is no data in this FaceSpace:" + FaceSpace + ",Please input ." << endl; }
}

string Recognition::Predict(cv::Mat LoadGetFace)//可优化，using CUDA TO COMPUTE
{
	if (!LoadGetFace.empty())
	{
		vector<float> v = ExtractFeature(Facedetect(LoadGetFace));

		if (!v.empty())
		{
			//cout << "v size" << v.size()<< endl;
			int ID = -1;
			float MaxCos = 0;
			for (int i = 0; i < NameVector.size(); i++)
			{
				//cout << "FaceMat["<<i<< "] " << FaceMat[i].at(0) << endl;
				//cout << "FaceMat[" << i << "] size" << FaceMat[i].size() << endl;

				
				float t_cos = cosine(v, FaceMat[i]);
				//for (int j = 0; j < 2622; j++) {
				//	cout << i <<","<< j << ": " << FaceMat[i][j] << "--"<< v[j]<<endl;
				//}
				cout << t_cos << endl;
				if (t_cos > MaxCos)
				{
					ID = i;
					MaxCos = t_cos;//update the coff
				}
			}
			if (ID != -1) {
				if (MaxCos < 0.9) {
					return "low";
				}
				else {
					return NameVector[ID];
				}
				
			}
			else {
				return "the face doesn't exists in the face store";
			}
		}
		else
		{
			return "The Picture does not have people's Face,Please try again.";
		}
	}
	return "The picture is empty.Please Check it and make sure.";

}

void Recognition::LoadRecognitionModel(vector<vector<float>> FaceMatrix, vector<string> NameVector_)//创建识别模型，需要输入FaceMarix，NameVector.
{
	if (!FaceMatrix.empty() && !NameVector_.empty())
	{
		FaceMat = FaceMatrix;
		NameVector = NameVector_;
	}
	else
	{
		cout << "Please check your FaceMatrix and NameVector.It may be empty." << endl;
	}
}

void Recognition::clear()
{
	//FaceMatrix_ = NULL;
	NameVector.clear();
}

void Recognition::update(vector<vector<float>> FaceMatrix, vector<string> NameVector)
{
	clear();
	LoadRecognitionModel(FaceMat, NameVector);
}


//pacificy add
vector<float> Recognition::MatToVector(cv::Mat TrainMat)
{
	vector<float> FaceVector;
	cv::Mat TrainMat_ROI = Facedetect(TrainMat);
	if (!TrainMat_ROI.empty())
		FaceVector =  ExtractFeature(TrainMat_ROI);
    return FaceVector;
}

//pacificy add
void Recognition::SaveVector(vector<vector<float>> FaceMatrix_, vector<string> FaceName_, string FaceSpace_) // save the people's  face vector
{
	//使用xml来存储数据
	if (!FaceMatrix_.empty() && !FaceName_.empty())
	{
		SaveFaceMatrix_(FaceMatrix_, "data/" + FaceSpace_ + "_FaceMatrix.xml", FaceName_.size());
		SaveNameVector(FaceName_, "data/" + FaceSpace_ + "_NameVector.txt");


	}
	else { cout << "Sorry.There are some problems while saving your face and name. please try again" << endl; }
}

//pacificy add
void Recognition::JoinFaceSpace(cv::Mat newFace, string FaceSpace, string Name)
{
	//vector<float> FaceVector = MatToVector(newFace);
	//cout <<"1:after ExtractFeature_"<< "--" << FaceVector[100] << "--" << FaceVector[500] << "--" << FaceVector[1000] << "--" << FaceVector[2621]<< endl;
	//for (int j = 0; j < 2622; j++) {
	//	cout << j << ":" << FaceVector[j] << endl;
	//}

	vector<float> FaceVector;
	cv::Mat TrainMat_ROI = Facedetect(newFace);
	if (!TrainMat_ROI.empty())
		FaceVector = ExtractFeature(TrainMat_ROI);

	if (!FaceVector.empty())//如果不为空，即存在人脸
	{
		//加入两个数据表
		FaceMat.push_back(FaceVector);
		NameVector.push_back(Name);
		//保存这两个数据表
		//格式为：矩阵类型；向量类型
		//下次可直接读入
		SaveVector(FaceMat, NameVector, FaceSpace);
	}
	else
	{
		cout << "Please try again,We can not find your face." << endl;
	}
}


