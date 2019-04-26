#include <ncurses.h>
#include <thread>
#include <Ball.h>
#include <unistd.h>
#include <vector>
#include <cstdlib>
#include <string>
#include <iostream>


using namespace std;

int xMax, yMax;
vector<Ball*> balls;
vector<thread> threads;
bool fin = true;

void refreshScreen()
{
	while(fin)
	{
		clear();
		for(unsigned int k=0;k < balls.size();k++)
		{

		    attron(COLOR_PAIR(balls.at(k)->kol));
            mvprintw(balls.at(k)->y,balls.at(k)->x, "X");
            attroff(COLOR_PAIR(balls.at(k)->kol));
		}
        mvprintw(yMax -10 , (xMax/2) - 8 , "oooooooo0oooooooo");



		//mvprintw(0,0,"");
		refresh();
		usleep(100000);

	}
}

void keylistener()
{
    if (getch() == 'x')
    {
        fin = false;

        for(unsigned int i=0; i < balls.size(); i++)
        {
            balls.at(i)->destroy = true;
        }
    }
}

int main()
{
    srand(time(NULL));
    initscr();

	getmaxyx(stdscr, yMax, xMax);

    thread screen(refreshScreen);

    thread key(keylistener);



    start_color();
    init_pair(1, COLOR_RED, COLOR_BLACK);
    init_pair(2, COLOR_GREEN, COLOR_BLACK);
    init_pair(3, COLOR_YELLOW, COLOR_BLACK);
    init_pair(4, COLOR_BLUE, COLOR_BLACK);
    init_pair(5, COLOR_MAGENTA, COLOR_BLACK);
    init_pair(6, COLOR_CYAN, COLOR_BLACK);

    curs_set(0);
    int licznik = 0;

while(fin){
            Ball *ball = new Ball();
            ball->x = xMax/2;
            ball->y = yMax;
            ball->delay = 10000* (rand()%5+5);
            ball->yMax = yMax;
            ball->xMax = xMax;

            switch(licznik)
            {
               case 0:
                {
                    ball->kol = licznik+1;
                    ball->movex = -1;//-3;
                    ball->movey = -1;//1;
                    break;
                }

                case 2:
                {
                    ball->kol = licznik+1;
                    ball->movex = 1;//-1;
                    ball->movey = 1;//3;
                    break;
                }
                   case 1:
                {
                    ball->kol = licznik+1;
                    ball->movex = 0;//-2;
                    ball->movey = -1;//2;
                    break;
                }
                case 3:
                {
                    ball->kol = licznik+1;
                    ball->movex = 0;//-2;
                    ball->movey = -1;//2;
                    break;
                }
                default: break;
            }
            balls.push_back(ball);
            threads.push_back(balls.at(licznik)->moveThread());
            licznik++;
            usleep(2000000);

}


 for(unsigned int i=0; i < threads.size(); i++)
        {
            threads.at(i).join();
        }

    key.join();
    screen.join();
	endwin();
    return 0;

}
