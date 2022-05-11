#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <unistd.h>

using namespace cv;
using namespace std;

int main(){

    Mat input_img;
    Mat change_color;

    VideoCapture cap(0);
    while (true) {
        cap >> input_img;
        cvtColor(input_img,change_color,COLOR_RGB2GRAY);
        imshow("GrayScale", change_color);
            if(waitKey(5) >= 0) break;
        }

    return 0;
}