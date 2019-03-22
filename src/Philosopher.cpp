#include "Philosopher.hpp"

Philosopher::Philosopher(int id)
{
    this->id = id;
}

std::stringstream Philosopher::changeColor(int code)
{
    if(code > 37)
        code += 3;
    std::stringstream ss;
    ss << "\033[0;" << code << "m";
    return ss;
}

std::stringstream Philosopher::eat(float time)
{
    std::stringstream ss;
    ss << changeColor(31 + id).str() << "Philosopher " << id << " will eat for " << time << " seconds" << " and put down forks" << std::endl;
    return ss;
}

std::stringstream Philosopher::thing(float time)
{
    std::stringstream ss;
    ss << changeColor(31 + id).str() << "Philosopher " << id << " will think for " << time << " seconds" << std::endl;
    return ss;
}

std::stringstream Philosopher::pickUp(std::string val)
{
    std::stringstream ss;
    ss << changeColor(31 + id).str() << "Philosopher " << id << " pick up " << val << " fork" << std::endl;
    return ss;
}

int Philosopher::randInt()
{
    std::mt19937 rd{ std::random_device{}()};
    std::uniform_int_distribution<int> distribution(2500,3500);
    return distribution(rd);
}

void Philosopher::Do()
{
    std::cout  << "Philosopher" << id << " start working" << std::endl;

    long waitTime;

    for(int i = 0; i < 10; i++)
    {
        waitTime = randInt();
        std::cout << pickUp("left").str();
        std::cout << pickUp("right").str();
        std::cout << eat((float)waitTime/1000).str();

        std::this_thread::sleep_for(std::chrono::milliseconds(waitTime));

        waitTime = randInt();
        std::cout << thing((float)waitTime/1000).str();
        std::this_thread::sleep_for(std::chrono::milliseconds(waitTime));  
    }

    std::cout << "Philosopher: " << id << " stop working" << std::endl;
}