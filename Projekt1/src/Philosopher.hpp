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

        int randInt();

        std::stringstream eat(float time);
        std::stringstream thing(float time);
        std::stringstream changeColor(int code);
        std::stringstream pickUp(std::string val);
        std::stringstream print(std::string val);
        

    public:
        Philosopher(int id);
        void Do();        
};