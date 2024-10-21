#ifndef VIDEOCAPTUREHANDLER_H  
#define VIDEOCAPTUREHANDLER_H  

#include "BaseHandler.h"  
#include <opencv2/opencv.hpp>  

class VideoCaptureHandler : public BaseHandler {
    cv::VideoCapture cap;
    int current_frame = 0;

public:
    VideoCaptureHandler(int argc, char** argv);
    ~VideoCaptureHandler();
    void run(int argc, char** argv);
    static void slider_callback(int pos, void* param);
};

#endif 