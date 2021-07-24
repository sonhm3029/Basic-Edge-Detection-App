#pragma once


#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/video/video.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/ml.hpp>
#include <opencv2/core/types_c.h>
#include <opencv2/core/core_c.h>
#include <opencv2/core/core.hpp>
//#include <opencv2/imgcodecs/imgcodecs_c.h>
#include <math.h>
#include <typeinfo>


//using namespace std;
using namespace cv;



class EdgeDectection
{
	Mat outputImg;
	public:
		int threshold = 0;
		EdgeDectection();
		~EdgeDectection();
		Mat sobelDetection(Mat inputImg);
		Mat robertDetection(Mat inputImg);
		Mat kirschDetection(Mat inputImg);
};

