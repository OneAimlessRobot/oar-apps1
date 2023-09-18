#include <iostream>
#include <unistd.h>
#include <thread>
#include <vector>
#include "auxFuncs.h"
#include <chrono>
#include "myTimer.h"
//
constexpr size_t COLLECTION_SIZE = 50000;
void operation(std::string arr[],size_t start,size_t finish){

    for(size_t i=start;i<finish;i++){
        std::string str="";
        randomNLongString(6,&str);
        arr[i]=str;
    }


}
int main(){


    std::string arr[COLLECTION_SIZE],arr2[COLLECTION_SIZE];
    std::vector<std::thread> workers;
    MyTimer timer;
    for(size_t i=0;i<COLLECTION_SIZE;i++){
    std::string str="";
        randomNLongString(6,&str);
        arr[i]=str;


    }
    MyTimer secondTimer;
    for(size_t i=0;i<COLLECTION_SIZE;i+=COLLECTION_SIZE/4){

        size_t start=i,finish=i+COLLECTION_SIZE/4;
        workers.push_back(std::thread(operation,arr2,start,finish));
        i+=COLLECTION_SIZE/4;

    }
    for(std::thread& i: workers){

        i.join();

    }
return 0;
}
