#ifndef MASTER_H
#define MASTER_H
class Master{

private:
std::set<Crush*> crushes;
CrushGenerator* gen;
Crush* menu();


public:

Master(std::string filePath);

void mainLoop();




};
#endif