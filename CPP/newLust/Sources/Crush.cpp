#include<string>
#include<iostream>
#include<fstream>
#include <math.h>
#include <unistd.h>
#include "../Includes/Crush.hpp"

    Crush::Crush(int id)
    {
        this->modelNo = id;

            this->genRandomIQ();
            this->genRandomEQ();
            this->genRandomStrength();
            this->genRandomWeight();
            this->genRandomHeight();
    }
    double Crush::calculateChance(){

        return 1-((this->getIQ()/400)*(this->getEQ()/100)*(((double)this->getStrength())/150));

    }
    Crush::Crush(std::string name)
    {

        this->name.assign(name);


            this->genRandomIQ();
            this->genRandomEQ();
            this->genRandomStrength();
            this->genRandomWeight();
            this->genRandomHeight();

            }
    Crush::Crush()
    {
        this->modelNo = 0;
        //Initialize all to zero
        for (int k = 0; k < 4;)
        {
            this->iq[k] = 0;
            k++;
        }
        for (int k = 0; k < 4;)
        {
            this->eq[k] = 0;
            k++;
        }
        for (int k = 0; k < 4;)
        {
            this->strengthPctg[k] = 0;
            k++;
        }

            this->weight = 0xFFFFFFF;
            this->height = 0;
        this->name = "";
    }

    void Crush::genRandomEQ(){

        for (int k = 0; k < 4;)
        {   //Um numero entre 0 e 100
            this->eq[k] = round(((random() / ((double)RAND_MAX + 1)) * 100));
            k++;
        }

    }
    void Crush::genRandomStrength(){

        for (int k = 0; k < 4;)
        {   //Um numero entre 0 e 100
            this->strengthPctg[k] = round(((random() / ((double)RAND_MAX + 1)) * 100)+50);
            k++;
        }

    }
    void Crush::genRandomIQ(){

        for (int k = 0; k < 4;)
        {   //Um numero entre 0 e 300 somado com 100
            this->iq[k] = round(((random() / ((double)RAND_MAX + 1)) * 300) + 100);
            k++;
        }
    }


    void Crush::genRandomHeight(){

            //Um numero entre 0 e 70 somado com 140. Alturas razoaveis em cm
            this->height = round(((random() / ((double)RAND_MAX + 1)) * 50)+140);
    }

    void Crush::genRandomWeight(){


            //Um numero entre 0 e 40 somado com 60. Massas razoaveis em kg
            this->weight = round(((random() / ((double)RAND_MAX + 1)) * 40) + 60);
    }

    void Crush::flirt()
    {

        sleep(3);
        std::cout << "\nOlha para ela, fofinho >). Este vai ser o dia da tua vida... Hmmmmm.... Ela quer te conhecer melhor 😳....mas não fiques com medo. Ela certamente que não morde...\n";
        usleep(500000);
        std::cout << "(A não ser que tu queiras, é claro 😘)\n\n";
        usleep(3000000);
        std::cout << "\nE Ela sabe o que é importante... esses " << this->getEQ() << " de QE não enganam 😌 \n";
        usleep(1000000);
        std::cout << "\nOs " << this->getStrength() << " de % de força levam-te a qualquer lado 😌 \n";
        usleep(1000000);
        std::cout << "\nE os " << this->getIQ() << " de QI dela garantem que sabe sempre o que vais fazer a seguir so de olhar para ti... \n";
        usleep(1000000);
        for(int i=0;i<5;i++){
        std::cout << "\n (NAO RESISTAS!!!!)\n";
        }
        usleep(1000000);
        sleep(3);
        }
    double Crush::getEQ()
    {

        return (this->eq[0] + this->eq[1] + this->eq[2] + this->eq[3]) / (double)4;
    }
    double Crush::getStrength()
    {

        return (this->strengthPctg[0] + this->strengthPctg[1] + this->strengthPctg[2] + this->strengthPctg[3]) / (double)4;
    }
    void Crush::printCrushFileLine(std::ofstream &file)
    {
        file << this->modelNo << "," << this->getIQ() << "," << this->getStrength() << "," << this->getEQ() << "," << this->getHeight() <<"," << this->getWeight()<< std::endl;
    }
    int Crush::getHeight(){
        return this->height;
    }
    int Crush::getWeight(){

        return this->weight;
    }

    void Crush::setHeight(int value){
        this->height=value;
    }
    void Crush::setWeight(int value){

        this->weight=value;
    }

    void Crush::printCrushLine()
    {

        std::cout << "O identificador desta crush é\n" << this->modelNo << "E Tem:\n" << this->getIQ() << " de QI\n" << this->getStrength() << " de Percentagem de força\n" << this->getEQ() << " de QE\n"<< this->getWeight() << " kg de massa\nE tem....\n"<< this->getHeight() << "cm de altura.\n";
    }
    void Crush::EQcopy(Crush *src, Crush *dest)
    {

        for (int k = 0; k < 4;)
        {
            dest->eq[k] = src->eq[k];
            k++;
        }
    }
    void Crush::strengthCopy(Crush *src, Crush *dest)
    {

        for (int k = 0; k < 4;)
        {
            dest->strengthPctg[k] = src->strengthPctg[k];
            k++;
        }
    }
    void Crush::IQcopy(Crush *src, Crush *dest)
    {

        for (int k = 0; k < 4;)
        {
            dest->iq[k] = src->iq[k];
            k++;
        }
    }
    std::string Crush::getName()
    {
        return this->name;
    }
    void Crush::rename(std::string newname)
    {
        this->name.assign(newname);
    }
    double Crush::getIQ()
    {
        return (this->iq[0] + this->iq[1] + this->iq[2] + this->iq[3]) / (double)4;
    }
    int Crush::getId()
    {
        return this->modelNo;
    }
    void Crush::setId(int value)
    {

        this->modelNo = value;
    }
    void Crush::crushCopy(Crush *src, Crush *dest)
    {

        dest->setId(src->getId());

        EQcopy(src, dest);


        strengthCopy(src, dest);

        IQcopy(src, dest);

        dest->setHeight(src->getHeight());
        dest->setWeight(src->getWeight());
        dest->name.assign(src->getName());
    }

    int Crush::pergunta()
    {

        double n = ((random() / ((double)RAND_MAX))),chanceOfFailure= this->calculateChance();

        std::cout << "\nVamos ver se a " << this->getName() << " gosta de ti:\n";
        sleep(3);

        int accepted = 0;

        if (n < chanceOfFailure)
        {
            sleep(3);
            std::cout << "Desculpa seu falhado, ela prefere alguém melhor, mesmo sendo um ser artificialmente criado por uma base de dados tua.\nAs tuas hipoteses eram: "<<(1-chanceOfFailure)*100<<" %\n";
        }
        else
        {
            accepted++;
            sleep(3);
            std::cout << "FOFO! Vai arranjar a fechadura que estragaste. Ela vai querer privacidade contigo 🤫 \nAs tuas hipoteses eram: "<<(1-chanceOfFailure)*100<<" %\n";
        }
        return accepted;
    }
