#include "task.hpp"
#include "iterator.hpp"
#include "cursor.hpp"
using namespace std;

class Manager
{
    task *list;
    cursor *c;
    int sizeOfList;

public:
    Manager(int size)
    {
        sizeOfList = size;
        list = new task[sizeOfList];
        c = new cursor(sizeOfList);
    }


    static void beep(){
        cout<<'\a'<<endl;
    }

    void fillListWithTasks(){

        for(int i=0;i<sizeOfList;i++){

            task l;

            list[i]=l;
        }
    }
    void addSpecifiedTask(string c,int i){

        task*aux=new task(c);
        list[i]=*aux;

    }

    bool listIsDone()
    {

        bool result = true;

        for (int i = 0; i < sizeOfList; i++)
        {
            result = result && list[i].isComplete();
        }

        return result;
    }
    
    int moveCursorRemote(int dist)
    {

        return c->move(dist);
    }
    int getCursorPosRemote()
    {
       return c->getPos();
    }

    char setToDoneRemote()
    {

    return(*(list+getCursorPosRemote())).setDone();
    }

    int countCompletedTasks(){

        int sum=0;
        for(int i=0;i<sizeOfList;i++){

            if(list[i].isComplete()){
                sum++;
            }
        }
        if(sum==sizeOfList){
            for(int i=0;i<3;i++){
            beep();
            usleep(750000);
            }
        }
        return sum;
        
    }
    taskIterator* giveIterator(){

        return new taskIterator(sizeOfList,list);
    }
    cursor* acessCursor(){
        return c;
    }
};