#pragma once
#include <vector>
#include <atomic>

#include "Fork.hpp"

class Table
{
    public:
        std::array<Fork, 5> forks;
        std::atomic<bool> ready{false};

        Table();
};