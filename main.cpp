#include "ExtractFeature_.h"
#include "FaceDetect.h"
#include "ComputeDistance.h"
#include "Register.h"
#include "Recognition.h"
#include <time.h>

int main()
{
	Caffe_Predefine();
	Dlib_Predefine();


	Recognition user,model;

	//初始化
	model.LoadVector("model");
	user.LoadVector("user");


	//识别
	//cv::Mat test = cv::imread("testmodel1.jpg");
	cv::Mat test = cv::imread("mike.jpg");
	string result = user.Predict(test);
	if (result == "low") {
		result = model.Predict(test);
		cout << "new user,recomend model:" << result << endl;
	}
	else {
		cout << "it's user:"<< result << endl;
	}

	
/*
	//新人添加头像信息
	string label;
	string path = "user/";                  
	string file_name = "mike";
	string suffix = ".jpg";
	string img_file = path + file_name + suffix;
	cv::Mat test = cv::imread(img_file);

	user.JoinFaceSpace(test, "user", file_name);
	*/

	/*
//注册
	Recognition Val;
	vector<cv::Mat> imgArray;
	vector<string> labelArray;
	for (int i = 0; i < 19; i++)//读入图片
	{
		string path = "model/";                    ////从前端的图片先获取特性，再保存到user
		string file_name = to_string(i);
		string suffix = ".jpg";
		string img_file = path + file_name+ suffix;
		cv::Mat img = cv::imread(img_file);
		imgArray.push_back(img);
		labelArray.push_back(file_name);
	}

	for (int j = 0; j < 19; j++) {
		Val.JoinFaceSpace(imgArray[j], "model", labelArray[j]);
	}
	*/

	imshow("Face Recognition", test);
	cv::waitKey(0);

	return 0;

} 