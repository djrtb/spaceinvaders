#include <graphics.h>
#include <math.h>
#include <conio.h>
#include <sstream>
#include <iostream>
#include <vector>
#include <iterator>
#include <Points.h>
#include <Triangle.h>
#include <vector>
#include <Bullet.h>
#include <Alien.h>

using namespace std;



int main(){
    int grErrCode;
    int gunpointX = 200, gunpointY = 500;
    int bound, boundY;
    int direction = 1;
    int tsize = 50;
    int startX = 0, startY = 0;
    int skips = 10;
    int bulletposition;
    int bulletCount = 0;
    int level = 1;
    int originalrateoffire = 1;
    int rateoffire = originalrateoffire;
    float angle;
    char shoot;
    Alien * invader = new Alien;
   // deque <Alien> invaders;
    vector <Bullet *> bullets;

    initwindow(500, 500);
    grErrCode = graphresult();
    if( grErrCode != grOk ){
        cout << " Graphics System Error: " << grapherrormsg(grErrCode) << endl;
        exit( 1 );
    }
    invader->initializeAlien(startX, startY, tsize);

    bound = getwindowwidth() - 56;
    boundY = getwindowheight() - 29;
    cout << boundY << "\n";


    while(invader->getriangle2()->gettPoints(2).getY() < getwindowheight()){
        cout << invader->getriangle1()->gettPoints(0).getX() << "  " << bound << " " << boundY << " " << direction << " " << skips << " " <<rateoffire <<"\n";
        setcolor(GREEN);
        rateoffire -= 1;
        //line(gunpointX, gunpointY, 250, 500);

//        if(!bullets.empty()){
//            if(bullets.front()->getPoints(1).getY() <= 0)
//                bullets.erase(bullets.at(0));
//        }

        cout << "This is the number of bullets in queue: " << bullets.size() << "\n";

        if(!bullets.empty()){
            for(int i = 0; i < bullets.size(); i++){
                bullets[i]->moveBullet();
            }
        }

//            for(int i = 0; i < bulletCount; i++){
//                bullets[i].moveBullet();
//                if(bullets[i].getPoints(1).getY() <= invader->getriangle1()->gettPoints(1).getY() &&
//                   bullets[i].getPoints(1).getX() >= invader->getriangle1()->gettPoints(1).getX() &&
//                   bullets[i].getPoints(1).getX() <= invader->getriangle2()->gettPoints(2).getX()){
////                    delete triangle;
////                    delete triangle2;
//                    outtextxy(250, 250, "HIT!");
//                   }
//            }
//            bulletposition = bulletposition - bulletSpeed;
//            line(gunpointX, bulletposition, gunpointX, bulletposition - 10);

        if(invader->getriangle1()->gettPoints(0).getX() >= bound){
            invader->moveDownFromRight();
            direction = 2;
        }
        else if(direction == 2 && invader->getriangle1()->gettPoints(0).getX() < 0){
            invader->moveDownFromLeft();
            direction = 1;
        }

        if(direction == 2){
            invader->moveLeft(skips);
        }
        else if(direction == 1){
            invader->moveRight(skips);
        }

        if(invader->getriangle1()->gettPoints(0).getY() < boundY * 0.3)
            skips = skips;
        else if(invader->getriangle1()->gettPoints(0).getY() > boundY * 0.3 && invader->getriangle1()->gettPoints(0).getY() < boundY * 0.6 ){
            skips = 30;
            originalrateoffire = 5;
            rateoffire = originalrateoffire;
        }
        else if(invader->getriangle1()->gettPoints(0).getY() > boundY * 0.6 && invader->getriangle1()->gettPoints(0).getY() < boundY * 0.9 ){
            skips = 60;
            originalrateoffire = 10;
            rateoffire = originalrateoffire;
        }
        else if(invader->getriangle1()->gettPoints(0).getY() > boundY * 0.9 && invader->getriangle1()->gettPoints(0).getY() < boundY){
            skips = 90;
            originalrateoffire = 15;
            rateoffire = originalrateoffire;
        }

        angle = atan2(500 - gunpointY, 250 - gunpointX);
        angle = angle + 0.08726;

        cout << " " << angle << " " << gunpointX << " " << gunpointY << " " << bulletCount;

        gunpointX = 250 + (50 * cos(angle));
        gunpointY = 500 + (50 * sin(angle));

        line(250, 500, gunpointX, gunpointY);
        //outtextxy(gunpointX, gunpointY, "FIRE");

        if(kbhit()){
            shoot = getch();

            if(shoot == ' ' && rateoffire == 0){
                bulletposition = gunpointY;
                Bullet * bullet = new Bullet;
                bullet->setInitialPosition(gunpointX, bulletposition);
                bullets.push_back(bullet);
//                    bullets[bulletCount].setInitialPosition(gunpointX, bulletposition);
//                    bulletCount += 1;
            }
        }

        cout << "This is rate of fire: " << rateoffire << "\n";

        if(rateoffire == 0)
            rateoffire = originalrateoffire;

        invader->getriangle1()->drawTriangle();
        invader->getriangle2()->drawTriangle();
        delay(100);
        cleardevice();
    }

}
