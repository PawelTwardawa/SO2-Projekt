#pragma once
#include <mutex>
#include <map>
#include <ncurses.h>
#include <vector>
#include "Philosopher.hpp"

class Ui
{
    public:
        int x;
        int y;
        std::mutex m;
        std::vector<Philosopher *>  philosophers;
        std::map<PhilosopherAction, const char *> actions = {
            std::pair<PhilosopherAction, const char *>(PhilosopherAction::Thinking , "thinking"), 
            std::pair<PhilosopherAction, const char *>(PhilosopherAction::Eating, "eating"), 
            std::pair<PhilosopherAction, const char *>(PhilosopherAction::waitingForForks, "waiting for forks")}; 

        Ui(std::vector<Philosopher *> p);
        ~Ui();
        void update();
};