
#include "BaseHandler.h"  
#include <sstream>  
#include <iostream>  

   BaseHandler::BaseHandler(int argc, char** argv) {
       cv::namedWindow(window_name, cv::WINDOW_NORMAL);
       cv::setMouseCallback(window_name, mouse_callback, this);
   }

   cv::Mat BaseHandler::reverse_and_show() {
       if (isreverse) {
           cv::Mat re_img;
           cv::bitwise_not(frame, re_img);
           cv::imshow(window_name, re_img);
           return re_img;
       }
       else {
           cv::imshow(window_name, frame);
           return frame;
       }
   }

   void BaseHandler::screen_img(cv::Mat frame) {
       std::ostringstream oss;
       oss << "µÚ" << img_index << "ÕÅÍ¼Æ¬.jpg";
       img_index++;
       cv::imshow(oss.str(), frame);
       cv::imwrite("C:\\Users\\»ÆºÆÐù\\source\\repos\\Project_opencv\\vedio\\img\\" + oss.str(), frame);
   }

   void BaseHandler::mouse_callback(int event, int x, int y, int flags, void* param) {
       BaseHandler* handler = (BaseHandler*)param;
       if (handler) {
           switch (event) {
           case cv::EVENT_LBUTTONDOWN:
               handler->isopen = !handler->isopen;
               break;
           case cv::EVENT_RBUTTONDOWN:
               handler->isreverse = !handler->isreverse;
               break;
           }
       }
   }