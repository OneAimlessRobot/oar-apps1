#include <iostream>
#include <array>
#include <string>
#include <stdio.h>
#include <unistd.h>
#include "Manager.hpp"

using namespace std;

const static string
    EXIT = "SAIR",
    MOVE_CURSOR = "MOVE",
    TICK_BOX = "TICK",
    CHECK_LIST = "CHECK_ALL",
    PRINT_LIST_STATUS = "PRINT",
    SPECIFIED_LIST = "SPEC",
    UNSPECIFIED_LIST = "UNSPEC",
    TEST = "TEST";

bool menu(string g, Manager *mgr);
void initialMenu();
void load();
void printMenu();
string ToUp(string c);
void printListStatus(Manager* mgr);

int main()
{

    int n, status;
    cout<<"Quantas tarefas queres? "<<endl;
    cin >> n;

    Manager *mgr = new Manager(n);
    string option;
    do
    {

        initialMenu();
        cin >> option;

        if (ToUp(option).compare(UNSPECIFIED_LIST) == 0)
        {

            mgr->fillListWithTasks();
        }
        else if (ToUp(option).compare(SPECIFIED_LIST) == 0)
        {
            cin.ignore();
            for (int i = 0; i < n; i++)
            {
                string desc;
                getline(cin, desc);
                mgr->addSpecifiedTask(desc, i);
            }
            cout << endl;
        }

    } while ((ToUp(option).compare(UNSPECIFIED_LIST) != 0) && (ToUp(option).compare(SPECIFIED_LIST) != 0));

    do
    {
        printMenu();
        char option[128];
        cin >> option;
        status = menu(option, mgr);

    } while (status);
}

bool menu(string g, Manager *mgr)
{
    bool res = true;

    if (ToUp(g).compare(EXIT) == 0)
    {

        res = false;
        cout<<"Terminaste "<<mgr->countCompletedTasks()<<" tarefas"<<endl;
    }
    else if (ToUp(g).compare(CHECK_LIST) == 0)
    {

        cout << mgr->countCompletedTasks() << endl;
    }
    else if (ToUp(g).compare(MOVE_CURSOR) == 0)
    {

        int n;
        cin >> n;
        if(mgr->moveCursorRemote(n)==1){
            cout<<"Ultrapassaste a lista, a posiçao nao mudara"<<endl;
        }

        printListStatus(mgr);
    }
    else if (ToUp(g).compare(TICK_BOX) == 0)
    {

        cout<<mgr->setToDoneRemote();
        printListStatus(mgr);
        
    }
    else if (ToUp(g).compare(PRINT_LIST_STATUS) == 0)
    {
        printListStatus(mgr);
    }
    return res;
}

void printMenu()
{

    cout << "As opcoes sao:" << endl;
    cout << EXIT << " - Para sair" << endl;
    cout << MOVE_CURSOR << " - Para mover cursor" << endl;
    cout << TICK_BOX << " - Para dar tick" << endl;
    cout << CHECK_LIST << " - Para verificar lista" << endl;
    cout << PRINT_LIST_STATUS << " - Para ver o estado da lista" << endl;
}
void initialMenu()
{
    cout << "As opcoes iniciais sao:" << endl;
    cout << SPECIFIED_LIST << " - Para uma lista especificada" << endl;
    cout << UNSPECIFIED_LIST << " - Para uma lista nao especificada" << endl;
}

string ToUp(string c)
{

    for (int i = 0; i < c.length(); i++)
    {

        c[i] = toupper(c[i]);
    }
    return c;
}

void load(){
        for(int i=0;i<3;i++){
            cout<<'.'<<endl;
            usleep(750000);
        }
}
void printListStatus(Manager* mgr){


        taskIterator *r = mgr->giveIterator();

        while (r->hasNext())
        {
            if(r->getSlot()==mgr->acessCursor()->getPos())
            {
                cout<<"> ";
        }

            task j = r->next();

            if (j.isComplete())
            {

                cout << "| ✓ " << j.getDesc() << endl;
            }
            else
            {
                cout << "| - " << j.getDesc() << endl;
            }
        }
        cout << endl;

}