#include "stdafx.h"
#include "lbp.h"

// ʼLBP  
Mat LBP(Mat img)
{
	Mat result;
	result.create(img.rows, img.cols, img.type());
	result.setTo(0);

	for (int i = 1; i<img.rows - 1; i++){
		for (int j = 1; j<img.cols - 1; j++){
			uchar center = img.at<uchar>(i, j);
			uchar code = 0;
			code |= (img.at<uchar>(i - 1, j - 1) >= center) << 7;
			code |= (img.at<uchar>(i - 1, j) >= center) << 6;
			code |= (img.at<uchar>(i - 1, j + 1) >= center) << 5;
			code |= (img.at<uchar>(i, j + 1) >= center) << 4;
			code |= (img.at<uchar>(i + 1, j + 1) >= center) << 3;
			code |= (img.at<uchar>(i + 1, j) >= center) << 2;
			code |= (img.at<uchar>(i + 1, j - 1) >= center) << 1;
			code |= (img.at<uchar>(i, j - 1) >= center) << 0;
			result.at<uchar>(i - 1, j - 1) = code;
		}
	}

	return result;
}
