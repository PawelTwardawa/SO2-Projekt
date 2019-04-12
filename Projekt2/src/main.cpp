#pragma once
#include <ncurses.h>
#include <iostream>
#include <vector>

//#include "Table.hpp"
#include "Philosopher.hpp"
//#include "Fork.hpp"


std::vector<Philosopher *> philosophers;
bool end = false;

int main()
{
    Table table;

    for(auto i = 0; i < 4; i++)
    {
        Philosopher *p = new Philosopher(i + 1, table, std::ref(table.forks[i]), std::ref(table.forks[i + 1]) );
        philosophers.push_back(p);

    }

    philosophers.push_back(new Philosopher(5, table, table.forks[4], table.forks[0]));

    std::cout<< "tu jestem";
    table.ready = true;

    for(auto p : philosophers)
    {
        p->t.join();
    }

}
    