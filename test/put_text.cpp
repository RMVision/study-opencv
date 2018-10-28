//
// Created by niracler on 18-10-28.
//

#include <iostream>
#include <opencv2/opencv.hpp>

int main() {
    //创建空白图用于绘制文字
    cv::Mat image = cv::Mat::zeros(cv::Size(640, 480), CV_8UC3);
    //设置蓝色背景
    image.setTo(cv::Scalar(100, 0, 0));

    //设置绘制文本的相关参数
    std::string text = std::to_string(8.88);
    int font_face = cv::FONT_HERSHEY_COMPLEX;
    double font_scale = 1;
    int thickness = 2;
    int baseline;

    //获取文本框的长宽
    cv::Size text_size = cv::getTextSize(text, font_face, font_scale, thickness, &baseline);

    //将文本框居中绘制
    cv::Point origin;
    origin.x = 0;
    origin.y = image.rows;
    cv::putText(image, text, origin, font_face, font_scale, cv::Scalar(0, 255, 255), thickness, 8, false);

    //显示绘制解果
    cv::imshow("image", image);
    cv::waitKey(0);
    return 0;
}