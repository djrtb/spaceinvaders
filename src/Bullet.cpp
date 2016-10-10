#include "Bullet.h"

Bullet::Bullet()
{
    //ctor
    this->bulletSpeed = 20;
    this->bulletLength = 10;
}

Bullet::Bullet(int gunPointX, int bulletPosition)
{
    //ctor
    this->bulletPoints = new Points[2];
    this->bulletPoints[0].setX(gunPointX);
    this->bulletPoints[0].setY(bulletPosition);
    this->bulletPoints[1].setX(gunPointX);
    this->bulletPoints[1].setY(bulletPosition - 10);
    line(this->bulletPoints[0].getX(), this->bulletPoints[0].getY(), this->bulletPoints[1].getX(), this->bulletPoints[1].getY());

}

Bullet::~Bullet()
{
    //dtor
    delete[] bulletPoints;
}
