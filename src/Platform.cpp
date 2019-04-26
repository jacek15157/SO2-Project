#include "Platform.h"
#include "Ball.h"
#include <string>
#include <thread>
#include <unistd.h>
#include <mutex>

std::mutex m1;
std::mutex m2;

Platform::Platform(int posX,int posY)
{
    sprite = "oooooooo";
    x = posX;
    y = posY;
}

Platform::Platform()
{
    sprite = "oooooooo";
}

Platform::~Platform()
{
    //dtor
}

void Platform::movePlatform()
{


}

void Platform::GetBall(Ball* ball){
    this->ball = ball;
}

std::thread Platform::movePlatformThread()
{
    return std::thread(&Platform::movePlatform,this);
}
const char *Platform::getSprite()
{
    return sprite.c_str();
}
