//
// Created by niracler on 18-12-1.
//

#include <opencv/cv.h>
#include <iostream>
#include <opencv/highgui.h>
#include <cv.hpp>

using namespace cv;
using namespace std;

int main() {

    char c;
    CvCapture *capture = cvCreateCameraCapture(2);

    IplImage *src;//一帧一帧的图片

    for (;;) {
        src = cvQueryFrame(capture);
        cvShowImage("Input", src);
        c = cvWaitKey(10);
        if (c == 27) break;
    }

    return 0;
}