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
        imshow("RGB", input_img);
            if(waitKey(5) >= 0) break;
    }
    
    return 0;
}