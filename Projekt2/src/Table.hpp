#pragma once
#include <vector>
#include <atomic>

#include "Fork.hpp"

class Table
{
    public:
        std::vector<Fork*> forks;
        Table();
        Table(int count);
};