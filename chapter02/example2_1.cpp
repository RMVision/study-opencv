//
// Created by niracler on 18-9-27.
//

# include <opencv2/opencv.hpp>

using namespace cv;

int main()
{
    Mat img = imread("../chapter02/girl.jpg");

    if(img.empty())
    {
        printf( "No image data \n" );
        return -1;
    }

    namedWindow("Example1", cv::WINDOW_AUTOSIZE);
    imshow("Example1", img);
    waitKey(0);

    destroyWindow("Example1");

    return 0;
}