#include <iostream>  
#include <opencv2/opencv.hpp>  
#include <string>  
#include <sstream>  
#include"BaseHandler.h"
#include"ImgHandler.h"
#include"VideoCaptureHandler.h"

bool isImageFormat(const std::string& ext) {
    return ext == "jpg" || ext == "jpeg" || ext == "png" || ext == "bmp" || ext == "tiff";
}

bool isVideoFormat(const std::string& ext) {
    return ext == "mp4" || ext == "avi" || ext == "mov" || ext == "mkv";
}

int main(int argc, char** argv) {
    bool is_image = false;
    if (argc >= 2) {
        std::string path = argv[1];
        size_t last_dot = path.find_last_of(".");
        if (last_dot != std::string::npos) {
            std::string path_ex = path.substr(last_dot + 1);
            is_image = isImageFormat(path_ex);
        }
    }

    if (argc < 2 || !is_image) {
        VideoCaptureHandler handler(argc, argv);
        handler.run(argc, argv);
    }
    else {
        ImgHandler imgHandler(argc, argv);
        imgHandler.run(argc, argv);
    }
   
    return 0;
}