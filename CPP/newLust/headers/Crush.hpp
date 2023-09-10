/*Incluir:
-string
-fstream
por esta ordem
*/
#ifndef CRUSH_H
#define CRUSH_H

class Crush
{
private:
    int modelNo,iq[4], eq[4],height,weight,strengthPctg[4];
    std::string name;
    double calculateChance();
    static void EQcopy(Crush *src, Crush *dest);
    static void IQcopy(Crush *src, Crush *dest);
    static void strengthCopy(Crush *src, Crush *dest);
    void genRandomIQ();
    void genRandomEQ();
    void genRandomStrength();
    void genRandomHeight();
    void genRandomWeight();

public:
    Crush(int id);
    Crush(std::string name);
    Crush();

    double getEQ();
    double getIQ();
    double getStrength();
    int getId();
    int getHeight();
    int getWeight();
    std::string getName();

    void printCrushFileLine(std::ofstream &file);
    void printCrushLine();


    void rename(std::string newname);
    void setId(int value);
    void setHeight(int value);
    void setWeight(int value);

    static void crushCopy(Crush *src, Crush *dest);

    int pergunta();
    void flirt();
};

#endif