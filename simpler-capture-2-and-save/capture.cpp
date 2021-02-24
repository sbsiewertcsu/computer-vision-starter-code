/*
 *
 *  Example by Sam Siewert  - older C API
 *
 *  Updated 10/29/16 for OpenCV 3.1
 *
 *  Updated 10/27/19 to save images
 *
 */
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace cv;
using namespace std;

#define HRES 640
#define VRES 480

char save_frame_name[]="frameNNNNNN.jpg";

int main( int argc, char** argv )
{
    cvNamedWindow("Capture Example", CV_WINDOW_AUTOSIZE);
    CvCapture* capture = cvCreateCameraCapture(1);
    IplImage* frame;
    unsigned int frameCnt=0;

    cvSetCaptureProperty(capture, CV_CAP_PROP_FRAME_WIDTH, HRES);
    cvSetCaptureProperty(capture, CV_CAP_PROP_FRAME_HEIGHT, VRES);

    while(1)
    {
        frame=cvQueryFrame(capture);
     
        if(!frame) break;

        cvShowImage("Capture Example", frame);

        frameCnt++;
        printf("frameCnt=%d\n", frameCnt);

        snprintf(&save_frame_name[5], 7, "%06d", frameCnt);
        strncat(&save_frame_name[11], ".png", 5);
        printf("save file name =%s\n", save_frame_name);
        cvSaveImage(save_frame_name, frame);

        char c = cvWaitKey(33);
        if( c == 'q' ) break;
    }

    cvReleaseCapture(&capture);
    cvDestroyWindow("Capture Example");
    
};
