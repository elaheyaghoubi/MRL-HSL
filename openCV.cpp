#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <unistd.h>

using namespace cv;
using namespace std;

int main(){

    Mat input_img;
    Mat change_color;
    int mode;

    cout << "which mode do you want?(1=RGB , 2=GrayScale)\n";
    cin >> mode;

    switch (mode){
                case 1 : {
                VideoCapture cap(0);
                
                while (true) {
                    cap >> input_img;
                    imshow("RGB", input_img);
                    if(waitKey(5) >= 0) break;
                }
                break;
            }
            case 2 : {
                VideoCapture cap(0);
                
                while (true) {
                    cap >> input_img;
                    cvtColor(input_img,change_color,COLOR_RGB2GRAY);
                    imshow("GrayScale", change_color);
                    if(waitKey(5) >= 0) break;
                }
                break;
            }
            default : cout<<"\nWrong key ...\n";break;
    }

    return 0;
}