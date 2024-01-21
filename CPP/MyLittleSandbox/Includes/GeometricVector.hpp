#ifndef GEO_VEC_H
#define GEO_VEC_H

enum Direction{

    positive,
    negative,


};
template<typename T>
class GeometricVector{

SDL_FPoint start,tip;
Direction direction;
T length,deltaX,deltaY;
void calculateTip();

public:
        GeometricVector(T startX,T startY,T deltaX,T deltaY,Direction directionInit,T length);

        void setTip(SDL_FPoint point);
        void setStart(SDL_FPoint point);
        void setDx(T value);
        void setDy(T value);
//        void disable();
//        void enable();
//        int isEnabled();

        void setDirection(Direction direction);
        void setLength(T value);

        SDL_FPoint getTip();
        SDL_FPoint getStart();
        int getDirection();
        T getLength();
        T getDx();
        T getDy();
        GeometricVector* getXComp();
        GeometricVector* getYComp();
        float getXLength();
        float getYLength();
        void render(SDL_Renderer* renderer,SDL_Color color);
        GeometricVector* add(GeometricVector* other);
        static GeometricVector* neutralVector(T x,T y);
        static float angleOf2Vectors(GeometricVector* vec1,GeometricVector* vec2);


};
#include "GeometricVector.tpp"

#endif