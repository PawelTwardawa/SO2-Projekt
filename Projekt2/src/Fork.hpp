#pragma once
#include <mutex>

struct Fork
{
    std::mutex mtx;
};


// class Fork
// {
//     public: 
//         static std::mutex mutex;

//         Fork();
// };