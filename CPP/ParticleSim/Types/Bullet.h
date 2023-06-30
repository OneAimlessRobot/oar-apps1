#ifndef BULLET_H
#define BULLET_H
class caliber{
public:
float size,mass,e,Car;
static caliber parseCaliber(std::string filePath);
static void printCaliberInfo(std::string filePath);
static caliber defaultCaliber();
};

#endif
