/**
Incluir:
-vector
-Structs.h

**/

#ifndef LIST_H
#define LIST_H

class CrushManager{

int ammount;
double quality;
public:
std::list<Crush> crushes;


CrushManager();
CrushManager(int ammount,int quality);


Crush findCrushWithId(long long int id);

void fillList();

/*https://stackoverflow.com/questions/10349857/how-to-handle-wrong-data-type-input*/
/*std::cout<<"Não lhe queres dar um nome? (Acaba quando carregares em ENTER)"<<std::endl sempre retorna 1
std::cin.getline(newname,80) retorna 0 num estado "mau" (input "errada")
(com micro modificações minhas para adaptar ao que eu quero)*/

void setup();

/*https://stackoverflow.com/questions/10349857/how-to-handle-wrong-data-type-input*/
/*std::cout<<"Não lhe queres dar um nome? (Acaba quando carregares em ENTER)"<<std::endl sempre retorna 1
std::cin.getline(newname,80) retorna 0 num estado "mau" (input "errada")
(com micro modificações minhas para adaptar ao que eu quero)*/

int afterResults();


Crush contestOfIQLonely();

Crush contestOfEQLonely();

Crush contestOfStrengthLonely();

Crush cyclistTestLonely();

Crush getSpecialcrushes();
};

#endif
