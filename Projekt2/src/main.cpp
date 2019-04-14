#pragma once
#include <ncurses.h>
#include <iostream>
#include <vector>
#include <thread>

//#include "Table.hpp"
#include "Philosopher.hpp"
#include "Ui.hpp"
//#include "Fork.hpp"

int count;

std::vector<Philosopher *> philosophers;
bool end = false;

int main(int argc, char **argv)
{
    if (argc != 2) {

        std::cout << "Podaj liczbe watkow" << std::endl;
        return 3;
    }
    else {

        std::string str(argv[1]);
        count = std::stoi(str);
    }

    Table *table = new Table(count);
    Table table2;

    std::cout<<table->forks.size();

    for(auto i = 0; i < count- 1; i++)
    {
        Philosopher *p = new Philosopher(i + 1, table2, *table->forks[i], *table->forks[i + 1] );
        philosophers.push_back(p);
    }

    philosophers.push_back(new Philosopher(count, table2, *table->forks[count -1], *table->forks[0]));

    std::thread tu(&Ui::update, new Ui(philosophers));

    tu.join();

    for(auto p : philosophers)
    {
        p->t.join();
    }
    endwin();
    return 0;
}
    