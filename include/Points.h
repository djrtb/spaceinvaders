#ifndef POINTS_H
#define POINTS_H


class Points
{
    public:
        Points();
        virtual ~Points();
        //Points(int, int);

        void setX(int x){
            this->x = x;
        }
        void setY(int y){
            this->y = y;
        }
        int getX(){
            return this->x;
        }
        int getY(){
            return this->y;
        }

    protected:
        int x;
        int y;

    private:
};

#endif // POINTS_H
