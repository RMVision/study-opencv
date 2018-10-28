//
// Created by niracler on 18-10-28.
//

/*
 * 【任务二】 利用投影投射原理，将lena图贴到广告牌上
Lena,广告牌,合成图像
提示：基本流程的matlab代码可以参考
 https://hk.saowen.com/a/caf48aafeb82aa8f2a506fcaf42a1c2c5285888f7d6c1e48244911759da4a138，
 需要自行查找资料，采用c++实现其功能
 * */

#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

void on_MouseHandle(int event, int x, int y, int flags, void *param);

Mat lena, ad;
int i = 0;
Point pt[4];

int main() {
    lena = imread("../img/lena.png", IMREAD_COLOR); // Read the file
    if (lena.empty()) {                    // Check for invalid input
        cout << "Could not open or find the image" << endl;
        return -1;
    }

    imshow("lena", lena);

    ad = imread("../img/ad.png", IMREAD_COLOR); // Read the file
    if (lena.empty()) {                    // Check for invalid input
        cout << "Could not open or find the image" << endl;
        return -1;
    }

    imshow("ad", ad);
    setMouseCallback("ad", on_MouseHandle);
    waitKey(0);

    return 0;
}

void on_MouseHandle(int event, int x, int y, int flags, void *param) {


    switch (event) {
        //左键按下消息
        case EVENT_LBUTTONDOWN: {
            pt[i] = Point(x, y);
            circle(ad, pt[i], 1, Scalar(0, 0, 255), 5);
            imshow("ad", ad);  //显示当前帧
            cout << pt[i].x << " " << pt[i].y << endl;

            i++;
            if (i == 4) {
                cout << "\nhello" << endl;
            }
        }
            break;

        default:
            break;
    }
}
