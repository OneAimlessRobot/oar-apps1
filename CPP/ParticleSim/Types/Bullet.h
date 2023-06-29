#ifndef BULLET_H
#define BULLET_H
typedef struct caliber{

float size,mass,e,Car;
caliber(float size,float mass,float e,float Car);

static stcaliber parseCaliber(std::string filePath);
caliber defaultCaliber();
}caliber;

#endif
