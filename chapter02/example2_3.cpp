//
// Created by niracler on 18-9-27.
//

#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace cv;

int main()
{
    namedWindow("Example3", cv::WINDOW_AUTOSIZE);
    VideoCapture cap;
    cap.open("../vedio/animation.mp4");

    Mat frame;
    while (true) {
        cap >> frame;
        if (frame.empty())
        {
            break;
        }

        imshow("Example3", frame);
        if(waitKey(100) >= 0)
        {
            break;
        }
    }

    return 0;
}