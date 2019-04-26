#include "Ball.h"
#include <thread>
#include <unistd.h>
#include <mutex>
#include <ncurses.h>
#include <condition_variable>

std:: mutex m1;
std:: condition_variable convar;
Ball::Ball()
{

}
bool isFree;
Ball::~Ball()
{
    //dtor
}

void Ball::moveOnScreen()
{

    while(!destroy)
    {
        if(x+movex > 80 || x+movex < 0)
        {
            movex = -movex;
        }

        if(y+movey > 24 || y+movey < 0)
        {
            movey = -movey;
        }

        this->x += movex;
        this->y += movey;
        usleep(delay);



        if( y== yMax-10 && x <= 48 && x>=32 ){
        convar.notify_all();
        std::unique_lock<std::mutex> mlock(m1);
        convar.wait(mlock);
        isFree = false;
    }

    }


}

std::thread Ball::moveThread()
{
    return std::thread(&Ball::moveOnScreen,this);
}

