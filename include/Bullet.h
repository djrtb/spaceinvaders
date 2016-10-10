#ifndef BULLET_H
#define BULLET_H
#include <graphics.h>
#include <Points.h>


class Bullet
{
    public:
        Bullet();
        Bullet(int, int);
        virtual ~Bullet();


        void setInitialPosition(int gunPointX, int bulletPosition){
            this->bulletPoints = new Points[2];
            this->bulletPoints[0].setX(gunPointX);
            this->bulletPoints[0].setY(bulletPosition);
            this->bulletPoints[1].setX(gunPointX);
            this->bulletPoints[1].setY(bulletPosition - 10);
            line(this->bulletPoints[0].getX(), this->bulletPoints[0].getY(), this->bulletPoints[1].getX(), this->bulletPoints[1].getY());
        }

        void moveBullet(){
            this->bulletPoints[0].setX(this->bulletPoints[0].getX());
            this->bulletPoints[0].setY(this->bulletPoints[0].getY() - this->bulletSpeed);
            this->bulletPoints[1].setX(this->bulletPoints[1].getX());
            this->bulletPoints[1].setY(this->bulletPoints[0].getY() - this->bulletLength);
            line(this->bulletPoints[0].getX(), this->bulletPoints[0].getY(), this->bulletPoints[1].getX(), this->bulletPoints[1].getY());
        }

        Points getPoints(int index){
            return this->bulletPoints[index];
        }

    protected:
        int bulletSpeed;
        int bulletLength;
        Points * bulletPoints;


    private:
};

#endif // BULLET_H
