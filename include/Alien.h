#ifndef ALIEN_H
#define ALIEN_H
#include <Points.h>
#include <Triangle.h>


class Alien
{
    public:
        Alien();
        virtual ~Alien();

        void initializeAlien(int x, int y, int tsize){
            this->tsize = tsize;
            this->trianglePoints1 = new Points[3];
            this->trianglePoints2 = new Points[3];
            this->triangle1 = new Triangle;
            this->triangle2 = new Triangle;


            this->trianglePoints1[0].setX(x);
            this->trianglePoints1[0].setY(y);
            this->trianglePoints1[1].setX(this->trianglePoints1[0].getX());
            this->trianglePoints1[1].setY(this->trianglePoints1[0].getY() + tsize);
            this->trianglePoints1[2].setX(this->trianglePoints1[0].getX() + tsize);
            this->trianglePoints1[2].setY(this->trianglePoints1[0].getY() + tsize);
            this->triangle1->setSize(this->tsize);
            this->triangle2->setSize(this->tsize);
            this->triangle1->setPoints(this->trianglePoints1);

            this->trianglePoints2[0].setX(this->triangle1->gettPoints(0).getX());
            this->trianglePoints2[0].setY(this->triangle1->gettPoints(0).getY());
            this->trianglePoints2[1].setX(this->triangle1->gettPoints(0).getX() + this->triangle2->getSize());
            this->trianglePoints2[1].setY(this->triangle1->gettPoints(0).getY());
            this->trianglePoints2[2].setX(this->triangle1->gettPoints(2).getX());
            this->trianglePoints2[2].setY(this->triangle1->gettPoints(2).getY());
            this->triangle2->setPoints(this->trianglePoints2);
        }



        int getTriangle1Point(){
            return this->triangle1->gettPoints(0).getX();
        }

        void moveDownFromRight(){
            this->trianglePoints1[0].setX(triangle1->gettPoints(0).getX());
            this->trianglePoints1[0].setY(triangle1->gettPoints(0).getY() + 20);
            this->trianglePoints1[1].setX(this->trianglePoints1[0].getX());
            this->trianglePoints1[1].setY(this->trianglePoints1[0].getY() + this->triangle1->getSize());
            this->trianglePoints1[2].setX(this->trianglePoints1[0].getX() + this->triangle1->getSize());
            this->trianglePoints1[2].setY(this->trianglePoints1[0].getY() + this->triangle1->getSize());
            this->triangle1->setSize(this->tsize);
            this->triangle2->setSize(this->tsize);
            this->triangle1->setPoints(this->trianglePoints1);

            this->trianglePoints2[0].setX(this->triangle1->gettPoints(0).getX());
            this->trianglePoints2[0].setY(this->triangle1->gettPoints(0).getY());
            this->trianglePoints2[1].setX(this->triangle1->gettPoints(0).getX() + this->triangle2->getSize());
            this->trianglePoints2[1].setY(this->triangle1->gettPoints(0).getY());
            this->trianglePoints2[2].setX(this->triangle1->gettPoints(2).getX());
            this->trianglePoints2[2].setY(this->triangle1->gettPoints(2).getY());
            this->triangle2->setPoints(this->trianglePoints2);
        }

        void moveDownFromLeft(){
            this->trianglePoints1[0].setX(triangle1->gettPoints(0).getX());
            this->trianglePoints1[0].setY(triangle1->gettPoints(0).getY() + 20);
            this->trianglePoints1[1].setX(this->trianglePoints1[0].getX());
            this->trianglePoints1[1].setY(this->trianglePoints1[0].getY() + this->triangle1->getSize());
            this->trianglePoints1[2].setX(this->trianglePoints1[0].getX() + this->triangle1->getSize());
            this->trianglePoints1[2].setY(this->trianglePoints1[0].getY() + this->triangle1->getSize());
            this->triangle1->setSize(this->tsize);
            this->triangle2->setSize(this->tsize);
            this->triangle1->setPoints(this->trianglePoints1);

            this->trianglePoints2[0].setX(this->triangle1->gettPoints(0).getX());
            this->trianglePoints2[0].setY(this->triangle1->gettPoints(0).getY());
            this->trianglePoints2[1].setX(this->triangle1->gettPoints(0).getX() + this->triangle2->getSize());
            this->trianglePoints2[1].setY(this->triangle1->gettPoints(0).getY());
            this->trianglePoints2[2].setX(this->triangle1->gettPoints(2).getX());
            this->trianglePoints2[2].setY(this->triangle1->gettPoints(2).getY());
            this->triangle2->setPoints(this->trianglePoints2);
        }
        void moveLeft(int skips){
            this->trianglePoints1[0].setX(triangle1->gettPoints(0).getX() - skips);
            this->trianglePoints1[0].setY(triangle1->gettPoints(0).getY());
            this->trianglePoints1[1].setX(this->trianglePoints1[0].getX());
            this->trianglePoints1[1].setY(this->trianglePoints1[0].getY() + this->triangle1->getSize());
            this->trianglePoints1[2].setX(this->trianglePoints1[0].getX() + this->triangle1->getSize());
            this->trianglePoints1[2].setY(this->trianglePoints1[0].getY() + this->triangle1->getSize());
            this->triangle1->setSize(this->tsize);
            this->triangle2->setSize(this->tsize);
            this->triangle1->setPoints(this->trianglePoints1);

            this->trianglePoints2[0].setX(this->triangle1->gettPoints(0).getX());
            this->trianglePoints2[0].setY(this->triangle1->gettPoints(0).getY());
            this->trianglePoints2[1].setX(this->triangle1->gettPoints(0).getX() + this->triangle2->getSize());
            this->trianglePoints2[1].setY(this->triangle1->gettPoints(0).getY());
            this->trianglePoints2[2].setX(this->triangle1->gettPoints(2).getX());
            this->trianglePoints2[2].setY(this->triangle1->gettPoints(2).getY());
            this->triangle2->setPoints(this->trianglePoints2);
        }
        void moveRight(int skips){
            this->trianglePoints1[0].setX(triangle1->gettPoints(0).getX() + skips);
            this->trianglePoints1[0].setY(triangle1->gettPoints(0).getY());
            this->trianglePoints1[1].setX(this->trianglePoints1[0].getX());
            this->trianglePoints1[1].setY(this->trianglePoints1[0].getY() + this->triangle1->getSize());
            this->trianglePoints1[2].setX(this->trianglePoints1[0].getX() + this->triangle1->getSize());
            this->trianglePoints1[2].setY(this->trianglePoints1[0].getY() + this->triangle1->getSize());
            this->triangle1->setSize(this->tsize);
            this->triangle2->setSize(this->tsize);
            this->triangle1->setPoints(this->trianglePoints1);

            this->trianglePoints2[0].setX(this->triangle1->gettPoints(0).getX());
            this->trianglePoints2[0].setY(this->triangle1->gettPoints(0).getY());
            this->trianglePoints2[1].setX(this->triangle1->gettPoints(0).getX() + this->triangle2->getSize());
            this->trianglePoints2[1].setY(this->triangle1->gettPoints(0).getY());
            this->trianglePoints2[2].setX(this->triangle1->gettPoints(2).getX());
            this->trianglePoints2[2].setY(this->triangle1->gettPoints(2).getY());
            this->triangle2->setPoints(this->trianglePoints2);

        }

        Triangle * getriangle2(){
            return this->triangle2;
        }

        Triangle * getriangle1(){
            return this->triangle1;
        }

    protected:
        int tsize;
        Triangle * triangle1;
        Triangle * triangle2;
        Points * trianglePoints1;
        Points * trianglePoints2;

    private:

};

#endif // ALIEN_H
