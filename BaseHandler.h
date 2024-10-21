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
    std::string window_name = "22376053 �ƺ���";

    BaseHandler(int argc, char** argv);
    cv::Mat reverse_and_show();//��ɫ����ʾ
    void screen_img(cv::Mat frame);//����
    static void mouse_callback(int event, int x, int y, int flags, void* param);
};

#endif