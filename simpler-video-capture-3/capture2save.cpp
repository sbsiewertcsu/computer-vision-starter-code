#include <string>

#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

char save_frame_name[]="frameNNNNNN.jpg";

int main(int argc, char** argv)
{

    cv::namedWindow("Example2", cv::WINDOW_AUTOSIZE);
    cv::VideoCapture cap;
    cap.open(std::string(argv[1]));
    unsigned int frameCnt=0;

    cv::Mat frame;

    for(;;)
    {
        cap >> frame;

        if(frame.empty()) break;

        frameCnt++;
        cv::imshow("Example2", frame);
        printf("frameCnt=%d\n", frameCnt);

        snprintf(&save_frame_name[5], 7, "%06d", frameCnt);
        strncat(&save_frame_name[11], ".png", 5);
        printf("save file name =%s\n", save_frame_name);

        cv::imwrite(save_frame_name, frame);

        if(cv::waitKey(33) >= 0) break;
    }

    return 0;
}

