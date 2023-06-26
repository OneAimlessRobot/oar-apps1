
#ifndef G_VEC
#define G_VEC
class GVector {

private:
float x,y;

public:
    GVector(float x,float y);
    float getX();
    float getY();
    void setX(float newX);
    void setY(float newY);
    float getNorm();
    static void Reflect(GVector* velocity, GVector* collisionNormal);
    static GVector* add(GVector* v1, GVector* v2);
    static float dotProduct(GVector*v1,GVector*v2);
    static float angleBetween(GVector* v1,GVector* v2);
    ~GVector();





};
#endif
