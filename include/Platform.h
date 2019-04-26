#ifndef PLATFORM_H
#define PLATFORM_H
#include <string>
#include "Ball.h"
#include <string>
#include <thread>
#include <unistd.h>

class Platform
{
      public:
        Platform(int posX,int posY);
        Platform();
        ~Platform();
        void movePlatform();
       // std::thread movePlatfromThread(Ball* ball);
        std::thread movePlatformThread();
        const char *getSprite();
         std::string sprite;
        int y;
        int x;
        void GetBall(Ball* ball);
        Ball* ball;

};

#endif // PLATFORM_H
