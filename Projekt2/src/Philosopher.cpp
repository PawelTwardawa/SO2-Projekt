#pragma once
#include "Philosopher.hpp"

void Philosopher::live()
{
    while(!exit)
    {
        think();
        action = PhilosopherAction::waitingForForks;
        eat();
    }
}

void Philosopher::think()
{
    action = PhilosopherAction::Thinking;
    int part = std::uniform_int_distribution<int>(15, 20)(rng);
    for(auto i = 1; i < part; i++)
    {
        if(exit)
        {
            return;
        }

        progress = ((double)i/part) * 100; 

        std::this_thread::sleep_for(std::chrono::milliseconds(200));
    }
}

void Philosopher::eat()
{
    std::lock(leftFork.mtx, rightFork.mtx);
    std::lock_guard<std::mutex> left_lock(leftFork.mtx, std::adopt_lock);
    std::lock_guard<std::mutex> right_lock(rightFork.mtx, std::adopt_lock);

    action = PhilosopherAction::Eating;
    int part = std::uniform_int_distribution<int>(15, 20)(rng);
    for(auto i = 1; i < part; i++)
    {
        if(exit)
        {
            return;
        }

        progress = ((double)i/part) * 100; 

        std::this_thread::sleep_for(std::chrono::milliseconds(200));
    }
}