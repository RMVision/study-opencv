#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;

int main()
{
    Mat image;
    image = imread( "../img/266679.png");

    if(image.empty())
    {
        printf( "No image data \n" );
        return -1;
    }

    namedWindow( "Display Image", CV_WINDOW_AUTOSIZE );
    imshow( "Display Image", image );

    waitKey(0);

    return 0;
}