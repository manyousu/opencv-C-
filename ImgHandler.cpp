#include "ImgHandler.h"  
#include <iostream>  

ImgHandler::ImgHandler(int argc, char** argv) : BaseHandler(argc, argv) {
    std::string path = argv[1];
    frame = cv::imread(path);
}

void ImgHandler::run(int argc, char** argv) {
    while (1) {
        if (frame.empty()) {
            std::cout << "Failed to open img!!" << std::endl;
            break;
        }

        reverse_and_show();

        int key = cv::waitKey(1);
        if (key == 's' || key == 'S') {
            screen_img(reverse_and_show());
        }
        if (key == 27) {
            break;
        }
    }
}