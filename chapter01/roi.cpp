//
// Created by niracler on 18-10-13.
// 截取出头像

# include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main()
{
    Mat pImg = imread("../img/266679.png");
    Rect rect(400, 100, 300, 300);//(x,y),w,h, 原点在左上角
    Mat roi = Mat(pImg, rect);
    Mat pImgRect = pImg.clone();

    rectangle(pImgRect, rect, Scalar(0, 255, 0, 2));

    imshow("ori", pImgRect);
    imshow("roi", roi);
    waitKey(0);

    return 0;
}