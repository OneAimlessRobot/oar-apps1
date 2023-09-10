#ifndef GEO_VEC_H
#define GEO_VEC_H

enum Direction{

    positive,
    negative,


};
template<typename T>
class GeometricVector{

SDL_Point start,tip;
Direction direction;
T length,deltaX,deltaY;
void calculateTip();

public:
        GeometricVector(int startX,int startY,T deltaX,T deltaY,Direction directionInit,T length);

        void setTip(SDL_Point point);
        void setStart(SDL_Point point);
        void setDx(T value);
        void setDy(T value);
//        void disable();
//        void enable();
//        int isEnabled();

        void setDirection(Direction direction);
        void setLength(T value);

        SDL_Point getTip();
        SDL_Point getStart();
        int getDirection();
        T getLength();
        T getDx();
        T getDy();
        GeometricVector* getXComp();
        GeometricVector* getYComp();
        double getXLength();
        double getYLength();
        void render(SDL_Renderer* renderer,SDL_Color color);
        GeometricVector* add(GeometricVector* other);
        static GeometricVector* neutralVector(int x,int y);
        static double angleOf2Vectors(GeometricVector* vec1,GeometricVector* vec2);


};
#include "GeometricVector.tpp"

#endif