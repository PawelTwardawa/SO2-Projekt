#include <iostream>
#include <thread> 
#include <random>
#include <sstream>
#include <chrono>
#include <string>


class Philosopher
{
    private: 
        int id;
        //bool work;

        int randInt();

        std::stringstream eat(float time);
        std::stringstream thing(float time);
        std::stringstream changeColor(int code);

    public:
        Philosopher(int id);
        void Do();
        //void StopDoing();
        
};