#include <iostream>
#include <opencv2/opencv.hpp>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "vector"
using namespace cv;
using namespace std;

void createAlphaMat(Mat &mat)
{
    for(int i =0; i < mat.rows; ++i) {
        for(int j = 0; j < mat.cols; ++j){
        Vec4b& rgba = mat.at<Vec4b>(i,j);
        rgba[0] = UCHAR_MAX;
        rgba[1] = saturate_cast<uchar>((float(mat.cols-j))/((float)mat.cols)*UCHAR_MAX);
        rgba[2] = saturate_cast<uchar>((float(mat.rows - i))/((float)mat.cols)*UCHAR_MAX);
        rgba[3] = saturate_cast<uchar>(0.5*(rgba[1] + rgba[2]));
        }
    }
}

int main()
{
    Mat mat(480,640,CV_8UC4);
    createAlphaMat(mat);

    vector<int>compression_params;
    compression_params.push_back(IMWRITE_PNG_COMPRESSION);
    compression_params.push_back(9);

    try{
        imwrite("1.jpg",mat,compression_params);
        imshow("生成",mat);
        fprintf(stdout,"可在工程目录下查看");
        waitKey(0);
    }
    catch (runtime_error& ex){
        fprintf(stderr,"发生错误",ex.what());
        return 1;
    }
    return 0;
}


//imread()
//int main()
//{
//    Mat src_img0 = imread("1.png",2|4);//无损
//    Mat src_img1 = imread("1.png",0);//灰度
//    Mat src_img2 = imread("1.png",1);//彩色
//
//    imshow("无损",src_img0);
//    imshow("灰度",src_img1);
//    imshow("彩色",src_img2);
//
//    waitKey(0);
//    return 0;
//}
//


