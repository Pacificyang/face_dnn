#include "FaceDetect.h"
#include "FaceRotate.h"
#include "FaceProcessing.h"

void Dlib_Predefine()
{
	deserialize("shape_predictor_68_face_landmarks.dat") >> sp;//读入标记点文件
}
cv::Mat Facedetect(cv::Mat frame)//脸是否存在
{

	int * pResults = NULL;

	//pBuffer is used in the detection functions.
	//If you call functions in multiple threads, please create one buffer for each thread!
	unsigned char * pBuffer = (unsigned char *)malloc(DETECT_BUFFER_SIZE);

	if (!pBuffer)
	{
		fprintf(stderr, "Can not alloc buffer.\n");
	}

	int doLandmark = 1;


	cv::Mat gray, error;
	cvtColor(frame, gray, CV_BGR2GRAY);

	pResults = facedetect_frontal_surveillance(pBuffer, (unsigned char*)(gray.ptr(0)), gray.cols, gray.rows, (int)gray.step,
		1.2f, 2, 48, 0, doLandmark);

	int peopleNUM = (pResults ? *pResults : 0);

	for (int i = 0; i < peopleNUM; i++)//代表有几张人脸(pResults ? *pResults : 0)
	{
		short * p = ((short*)(pResults + 1)) + 142 * i;
		int x = p[0];
		int y = p[1];
		int w = p[2];
		int h = p[3];
		int neighbors = p[4];
		int angle = p[5];

		cv::Rect opencvRect(x, y, w, h);

		//gray = gray(opencvRect);
		dlib::rectangle dlibRect((long)opencvRect.x, (long)opencvRect.y, (long)(opencvRect.x + opencvRect.width), (long)(opencvRect.y + opencvRect.height));
		dlib::full_object_detection shape = sp(dlib::cv_image<uchar>(gray), dlibRect);//标记点
		std::vector<full_object_detection> shapes;
		shapes.push_back(shape);//把点保存在了shape中
		dlib::array<array2d<rgb_pixel>>  face_chips;
		extract_image_chips(dlib::cv_image<uchar>(gray), get_face_chip_details(shapes), face_chips);
		cv::Mat pic = toMat(face_chips[0]);
		cvtColor(pic, pic, CV_BGR2GRAY);
		resize(pic, pic, cv::Size(224, 224));
		return FaceProcessing(pic);
	}
	return error;//如果没有检测出人脸 将返回一个空矩阵
}