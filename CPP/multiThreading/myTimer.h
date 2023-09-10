
#ifndef MYTIMER_H
#define MYTIMER_H
using namespace std::literals::chrono_literals;
class MyTimer{


private:

    std::chrono::time_point<std::chrono::system_clock> start,finish;
    std::chrono::duration<float> duration;
public:

    MyTimer();
    ~MyTimer();





};


#endif