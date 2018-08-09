#include "SaveVector.h"
cv::Mat Vector2dToMat(float *FaceMatrix[], int rows)
{
	//know FaceMatrix's col and row.
	//FaceVector->Mat
	cv::Mat T(rows, 2622, CV_32F);
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < 2622; j++)
		{
		T.at<float>(i, j) = FaceMatrix[i][j];
		}
	return T;
}

//pacificy add
cv::Mat Vector2dToMat_(vector<vector<float>> FaceMatrix, int rows)
{
	//know FaceMatrix's col and row.
	//FaceVector->Mat
	cv::Mat T(rows, 2622, CV_32F);
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < 2622; j++)
		{
			T.at<float>(i, j) = FaceMatrix[i][j];
		}
	return T;
}
void SaveMat(cv::Mat &FaceMatrix_, string filename)
{
	cv::FileStorage fs(filename, cv::FileStorage::WRITE);
	fs << "FaceMatrix" << FaceMatrix_;
	fs.release();
}
cv::Mat LoadMat(string file)//文件名
{
	cv::FileStorage fs(file, cv::FileStorage::READ);
	cv::Mat FaceMatrix_;
	fs["FaceMatrix"] >> FaceMatrix_;
	return FaceMatrix_;
}
float** MatToVector2d(cv::Mat &FaceMatrix_mat)
{
	float **array2d = new float*[FaceMatrix_mat.rows];
	for (int i = 0; i < FaceMatrix_mat.rows; ++i)
		array2d[i] = new float[FaceMatrix_mat.cols];

	for (int i = 0; i < FaceMatrix_mat.rows; ++i)
		array2d[i] = FaceMatrix_mat.ptr<float>(i);

	return array2d;
}

void SaveFaceMatrix(float *FaceMatrix[], string filename, int rows)
{
	// 将FaceMatrix拿出来
	cv::Mat T = Vector2dToMat(FaceMatrix, rows);
	//cout << "3:after get T" << "--" << T.at<float>(0,100) << "--" << T.at<float>(0, 500) << "--" << T.at<float>(0, 1000) << "--" << T.at<float>(0, 2621) << endl;
	//for (int j = 0; j < 2622; j++) {
	//	cout << j << ":" << T.at<float>(0,j) << endl;
	//}
	if (!T.empty())
		SaveMat(T, filename);
	else
	{
		cout << "Please check out your the matrix and the file.We can not read any information." << endl;
		exit(0);
	}
}

//pacificy add
void SaveFaceMatrix_(vector<vector<float>> FaceMatrix, string filename, int rows)
{
	// 将FaceMatrix拿出来
	cv::Mat T = Vector2dToMat_(FaceMatrix, rows);
	//cout << "3:after get T" << "--" << T.at<float>(0,100) << "--" << T.at<float>(0, 500) << "--" << T.at<float>(0, 1000) << "--" << T.at<float>(0, 2621) << endl;
	//for (int j = 0; j < 2622; j++) {
	//	cout << j << ":" << T.at<float>(0,j) << endl;
	//}
	if (!T.empty())
		SaveMat(T, filename);
	else
	{
		cout << "Please check out your the matrix and the file.We can not read any information." << endl;
		exit(0);
	}
}

//存储姓名
void SaveNameVector(vector<string>   &NameVector, string filename)
{
	ofstream NameSaveFile(filename, ios::app);
	NameSaveFile << NameVector[NameVector.size() - 1] << endl;
	NameSaveFile.clear();
}
vector<string> LoadNameVector(vector<string>   &NameVector_, string filename)
{
	ifstream in(filename);
	int Num = 0;
	string line;
	if (in){
		while (getline(in, line))
		{
			NameVector_.push_back(line);
		}
	}
	in.clear();
	return NameVector_;
}

vector<vector<float> >  LoadFaceMatrix(string FaceVectorRoad)
{
	cv::Mat faceMatrix = LoadMat(FaceVectorRoad);

	cout << "faceMatrix.rows: "  <<faceMatrix.rows << endl;
	cout << "faceMatrix.cols: " << faceMatrix.cols << endl;

	vector<vector<float> > FaceVector;
	vector<float> Face;
	//vector<float> *Face = new vector<float>();

	for (int i = 0; i < faceMatrix.rows; i++)
	{
		for (int j = 0; j < faceMatrix.cols; j++)
		{
			Face.push_back(faceMatrix.at<float>(i, j));
			
		}
		FaceVector.push_back(Face);
		Face.clear();
		
			//for (int j = 0; j < faceMatrix.cols; j++)
			//{
			//	cout << "faceMatrix.at<float>(" << i << ",  " << j << "):" << faceMatrix.at<float>(i, j) << endl;
			//	cout << "FaceVector[i][j]" << FaceVector[i][j] << endl;

			//}
	}

	return FaceVector;
		

}

float** LoadFaceMat(string FaceVectorRoad)
{
	cv::Mat faceMatrix = LoadMat(FaceVectorRoad);
	float **array2d = MatToVector2d(faceMatrix);
	return array2d;
}