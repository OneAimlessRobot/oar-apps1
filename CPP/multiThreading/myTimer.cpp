#include <iostream>
#include<chrono>
#include "myTimer.h"

MyTimer::MyTimer(){

    this->start=std::chrono::high_resolution_clock::now();

}
MyTimer::~MyTimer(){
    this->finish= std::chrono::high_resolution_clock::now();
    duration= finish-start;
    std::cout<<"Este timer durou "<<duration.count()*1000<<" segundos!!!\n";

}