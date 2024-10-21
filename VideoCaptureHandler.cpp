#include "VideoCaptureHandler.h"  
#include <iostream>  

VideoCaptureHandler::VideoCaptureHandler(int argc, char** argv) : BaseHandler(argc, argv) {
    if (argc == 1) {
        cap.open(0);
    }
    else {
        std::string path = argv[1];
        cap.open(path);
    }

    if (!cap.isOpened()) {
        std::cout << "Video is not opened correctly!!!" << std::endl;
        exit(-1);
    }

    int frame_count = (int)cap.get(cv::CAP_PROP_FRAME_COUNT);
    if (argc != 1) {
        cv::createTrackbar("进度条", window_name, &current_frame, frame_count, slider_callback, this);
    }
}

VideoCaptureHandler::~VideoCaptureHandler() {
    cap.release();
    cv::destroyAllWindows();
}

void VideoCaptureHandler::run(int argc, char** argv) {
    int fps = cap.get(cv::CAP_PROP_FPS);
    while (true) {
        if (isopen) {
            cap.read(frame);
            if (frame.empty()) {
                std::cout << "Fail to capture img!!!" << std::endl;
                break;
            }
            current_frame = (int)cap.get(cv::CAP_PROP_POS_FRAMES);
            if (current_frame % 10 == 0 && argc != 1) {
                cv::setTrackbarPos("进度条", window_name, current_frame);
            }

            reverse_and_show();
            int key = cv::waitKey(800 / fps);
            if (key == 's' || key == 'S') {
                screen_img(reverse_and_show());
            }
            if (key == 27) {
                break;
            }
        }
        else {
            int key = cv::waitKey(1);
            if (key == 's' || key == 'S') {
                screen_img(reverse_and_show());
            }
            reverse_and_show();
            if (key == 27) {
                break;
            }
        }
    }
}

void VideoCaptureHandler::slider_callback(int pos, void* param) {
    VideoCaptureHandler* handler = (VideoCaptureHandler*)param;
    handler->cap.set(cv::CAP_PROP_POS_FRAMES, pos);
}