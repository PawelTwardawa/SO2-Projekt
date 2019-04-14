#pragma once
#include <mutex>
#include <condition_variable>

class Fork
{
    public: 
        std::mutex mtx;
        std::condition_variable ready_cv;
        int last_id = -1;
};
