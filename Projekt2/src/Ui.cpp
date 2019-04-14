#pragma once
#include "Ui.hpp"

Ui::Ui(std::vector<Philosopher *> p)
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
    x = 0;
    y = 0;
}

Ui::~Ui()
{
    endwin();
}

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
            move(y + p->id, 0);
            clrtoeol();
            attron(COLOR_PAIR((int)p->action));
            if(p->action == PhilosopherAction::waitingForForks)
            {
                mvprintw(y + p->id, x, "Philosopher %d is %s", p->id, actions[p->action]);
            }
            else
            {
                mvprintw(y + p->id, x,"Philosopher %d is %s ", p->id, actions[p->action]);
                mvprintw(y + p->id, x + 40 ," progress: %d %", p->progress);
                clrtoeol();
            }
            refresh();
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
    }
}