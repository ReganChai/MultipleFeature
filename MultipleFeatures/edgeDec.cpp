#include "stdafx.h"
#include "edgeDec.h"

Mat EdgeDetection(Mat img)
{
	Mat src;
	img.copyTo(src);

	int kernel_size = 3;
	Mat kernel = (Mat_<float>(kernel_size, kernel_size));
	for (int i = 0; i < kernel_size; i++){
		for (int j = 0; j < kernel_size; j++){
			if (i == 1 && j == 1)
				kernel.ptr<float>(i)[j] = -0.7976;
			else
				kernel.ptr<float>(i)[j] = 0.0997;
		}
	}
	
	// 初始化滤波器参数---分数阶
	Mat dst;
	Point anchor = Point(-1, -1);
	double delta = 0;
	int ddepth = -1;
	//将核设置好之后，使用函数 filter2D 就可以生成滤波器：
	filter2D(src, dst, ddepth, kernel, anchor, delta, BORDER_DEFAULT);
	normalize(dst, dst, 0, 255, NORM_MINMAX);

	return dst;
}
