#pragma once
#include <mutex>
#include <random>
#include <thread>
#include <vector>

//#include "Fork.hpp"
#include "Table.hpp"

class Philosopher
{
    public:
        int id;
        Table &table;
        Fork &leftFork;
        Fork &rightFork;
        std::thread t;
        std::mt19937 rng{std::random_device{}()};
        int state = -1;
        int progress = 0;

        std::mutex mutex;
        bool exit = false;

        Philosopher(int i, Table &tab, Fork &l, Fork &r): id(i), table(tab), leftFork(l), rightFork(r), t(&Philosopher::live, this) {};
        void live();
        void eat();
        void think();
    
};