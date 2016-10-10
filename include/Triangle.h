#ifndef TRIANGLE_H
#define TRIANGLE_H
#include <Points.h>
#include <graphics.h>


class Triangle
{
    public:
        Triangle();
        virtual ~Triangle();
        //Triangle(int, Points p[]);
        void setSize(int tsize){
            tSize = tsize;
        }
        int getSize(){
            return tSize;
        }
        void setPoints(Points  p[]){
            this->trianglePoints = new Points[3];
            this->trianglePoints = p;
        }
        Points gettPoints(int index){
            return trianglePoints[index];
        }
        void drawTriangle(){
            line(trianglePoints[0].getX(), trianglePoints[0].getY(), trianglePoints[1].getX(), trianglePoints[1].getY());
            line(trianglePoints[1].getX(), trianglePoints[1].getY(), trianglePoints[2].getX(), trianglePoints[2].getY());
            line(trianglePoints[2].getX(), trianglePoints[2].getY(), trianglePoints[0].getX(), trianglePoints[0].getY());
        }

    protected:
        int tSize;
        Points * trianglePoints;

    private:
};

#endif // TRIANGLE_H
