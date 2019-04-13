#pragma once
#include <ncurses.h>
#include <iostream>
#include <vector>
#include <thread>

//#include "Table.hpp"
#include "Philosopher.hpp"
#include "Ui.hpp"
//#include "Fork.hpp"


std::vector<Philosopher *> philosophers;
bool end = false;

int main(int argc, char **argv)
{
    Table *table = new Table(5);
    //table->forks.resize(5);
    Table table2;

    std::cout<<table->forks.size();
    //Ui *ui = new Ui();

    for(auto i = 0; i < 4; i++)
    {
        Philosopher *p = new Philosopher(i + 1, table2, std::ref(table->forks[i]), std::ref(table->forks[i + 1]) );
        philosophers.push_back(p);

    }

    philosophers.push_back(new Philosopher(5, table2, table->forks[4], table->forks[0]));

    table->ready = true;

    std::thread tu(&Ui::update, new Ui(philosophers));

    tu.join();

    for(auto p : philosophers)
    {
        p->t.join();
    }
    endwin();
    return 0;
}
    