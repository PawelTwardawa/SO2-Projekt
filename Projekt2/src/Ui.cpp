#pragma once
#include "Ui.hpp"

Ui::Ui(std::vector<Philosopher *> p)
//Ui::Ui()
{
    philosophers = p;
    initscr();
    noecho();
    raw();
    nodelay(stdscr, true);
    start_color();
    use_default_colors();
    curs_set(0);
    init_pair(1, COLOR_MAGENTA, -1);
    init_pair(2, COLOR_GREEN, -1);
    init_pair(3, COLOR_RED, -1);
    getmaxyx(stdscr, col, row);
    x = row/2 -max_len;
    y = col /2;
};

Ui::~Ui()
{
    endwin();
};

void Ui::update()
{
    while(true)
    {
        int c = getch();
        if(c == 113)
        {
            for(auto p : philosophers)
            {
                p->exit = true;
            }
            return;
        }

        for(auto p : philosophers)
        {
            //int id = p->id;
            //int state = p->state;
            move(y + p->id -2, 0);
            clrtoeol();
            attron(COLOR_PAIR(p->state + 1));
            if(p->state == 2)
            {
                mvprintw(y + p->id -2, x, "Philosopher %d is %s", p->id, states[p->state]);
            }
            else
            {
                mvprintw(y + p->id- 2, x,"Philosopher %d is %s ", p->id, states[p->state]);
                mvprintw(y + p->id- 2, x + 40 ," progress: %d %", p->progress);
                clrtoeol();
            }
            refresh();
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
    }
};