#pragma once
#include "Philosopher.hpp"

// Philosopher::Philosopher(int i, Table &tab, Fork &l, Fork &r) : id(i), table(tab), leftFork(l), rightFork(r), t(&Philosopher::live, this)
// {
//     // id = i;
//     // table = &tab;
//     // leftFork = l;
//     // rightFork = r;

//     // t = std::thread(&Philosopher::live, this);

// };


void Philosopher::live()
{
    while(!exit)
    {
        think();
        state = 2;
        eat();
    }
};

void Philosopher::think()
{
    state = 0;

    int part = std::uniform_int_distribution<int>(15, 20)(rng);
    for(auto i = 1; i < part; i++)
    {
        if(exit)
        {
            return;
        }

        double p = (double)i /(double)part;

        progress = std::round(p * 100);

        std::this_thread::sleep_for(std::chrono::milliseconds(200));
    }
};

void Philosopher::eat()
{
    std::lock(leftFork.mtx, rightFork.mtx);
    std::lock_guard<std::mutex> left_lock(leftFork.mtx, std::adopt_lock);
    std::lock_guard<std::mutex> right_lock(rightFork.mtx, std::adopt_lock);

    // std::lock(leftFork.mtx, rightFork.mtx);
    // std::lock_guard<std::mutex> left_lock(leftFork.mtx, std::adopt_lock);
    // std::lock_guard<std::mutex> right_lock(rightFork.mtx, std::adopt_lock);

    state = 1;
    int part = std::uniform_int_distribution<int>(15, 20)(rng);
    for(auto i = 1; i < part; i++)
    {
        if(exit)
        {
            return;
        }

        double p = (double)i /(double)part;

        progress = std::round(p * 100);

        std::this_thread::sleep_for(std::chrono::milliseconds(200));
    }
};