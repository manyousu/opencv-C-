#ifndef BASEHANDLER_H  
#define BASEHANDLER_H  

#include <opencv2/opencv.hpp>  
#include <string>  

class BaseHandler {
protected:
    cv::Mat frame;
    bool isopen = true;
    bool isreverse = false;
    int img_index = 1;
    std::string window_name = "22376053 »ÆºÆÐù";

    BaseHandler(int argc, char** argv);
    cv::Mat reverse_and_show();//·´É«¼æÏÔÊ¾
    void screen_img(cv::Mat frame);//½ØÆÁ
    static void mouse_callback(int event, int x, int y, int flags, void* param);
};

#endif