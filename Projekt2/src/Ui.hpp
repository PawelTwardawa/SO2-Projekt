#pragma once
#include <mutex>
#include <map>
#include <ncurses.h>
#include <vector>
#include "Philosopher.hpp"

class Ui
{
    public:
        int row;
        int col;
        int x;
        int y;
        const int max_len = 46;
        std::mutex m;
        std::vector<Philosopher *>  philosophers;
        std::map<int, const char *> states = {
            std::pair<int, const char *>(-1, "waiting for table"),
            std::pair<int, const char *>(0, "thinking"), 
            std::pair<int, const char *>(1, "eating"), 
            std::pair<int, const char *>(2, "waiting for forks")}; 

        //Ui();
        Ui(std::vector<Philosopher *> p);
        ~Ui();
        void printInitialState();
        void updateState(int id, const char *state, int progress);
        void update();
};