
#ifndef IMGHANDLER_H  
#define IMGHANDLER_H  

#include "BaseHandler.h"  

class ImgHandler : public BaseHandler {
public:
    ImgHandler(int argc, char** argv);
    void run(int argc, char** argv);
};

#endif 