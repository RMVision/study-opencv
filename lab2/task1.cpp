#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

/*VideoCapture类，调用摄像头来对视频进行读取，
 * a.通过分别在两个不同的窗口显示采集到的彩色图像和灰度图像 (ok)
        提示：可参考https://blog.csdn.net/coldplayplay/article/details/70211828?utm_source=blogxgwz8
    b.计算采样帧率，实时显示在图像窗口；
        提示：获取系统时间，如gettimeofday（linux系统下），通过计算两帧时间差来计算帧率
    c.在图像中心画出标记线，（一个十字叉 + 一个圆形标记，尺寸自己定义）
        提示：OpenCV里画图相关函数可以参考https://docs.opencv.org/3.1.0/dc/da5/tutorial_py_drawing_functions.html
 * */



int main() {
    //设置绘制文本的相关参数
    int font_face = cv::FONT_HERSHEY_COMPLEX;
    Scalar color(0, 255, 255);
    double font_scale = 1;
    int thickness = 2;
    cv::Point origin;

    //记录时间的参数
    clock_t cstart, cends;

    //【1】从摄像头读入视频
    VideoCapture capture(0);
    if (!capture.isOpened()) {
        cout << "cannot open the camera.";
        cin.get();
        return -1;
    }

    Mat edges; //定义一个Mat变量，用于存储每一帧的图像
    cstart = clock();

    //【2】循环显示每一帧
    while (true) {
        Mat frame; //定义一个Mat变量，用于存储每一帧的图像
        capture >> frame;  //读取当前帧

        if (frame.empty()) {
            printf("--(!) No captured frame -- Break!");
        } else {
            cends = clock();
            double duration = (double) (cends - cstart) / CLOCKS_PER_SEC;
            cstart = cends;

            origin.x = frame.cols / 2;
            origin.y = frame.rows / 2;
            int r = 70;//半径
            circle(frame, origin, r, color, thickness);//参数为：承载的图像、圆心、半径、颜色、粗细、线型
            int size = 30;
            line(frame, Point(origin.x - size, origin.y), Point(origin.x + size, origin.y), color, thickness);//绘制横线
            line(frame, Point(origin.x, origin.y - size), Point(origin.x, origin.y + size), color, thickness);//绘制竖线


            origin.x = 0;
            origin.y = frame.rows;
            putText(frame, to_string(duration), origin, font_face, font_scale, color, thickness);

            imshow("原始的视频", frame);
            cvtColor(frame, edges, CV_BGR2GRAY);//彩色转换成灰度
            imshow("转化为灰度图像后的视频", edges);
        }

        waitKey(30); //延时30ms
    }
    return 0;
}