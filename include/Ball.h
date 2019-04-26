#ifndef BALL_H
#define BALL_H
#include <thread>

class Ball
{
    public:
        bool destroy = false;
        Ball();
        virtual ~Ball();
        int x;
        int y;
        int kol;
        int yMax;
        int xMax;
        int movex;
        int movey;
        int delay ;//= 99000;
        void moveOnScreen();
        std::thread moveThread();
    protected:


};

#endif // BALL_H

