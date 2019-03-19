#include <iostream> 
#include <vector>
#include <thread>
#include  "Philosopher.hpp"

using namespace std;

int main(int argc, char **argv)
{
    vector<thread> threads(1);
    int numberOfThreads = 5;

    if(argc == 2)
    {
        std::string arg(argv[1]);
        numberOfThreads = std::stoi(arg);
        cout << "START WITH " << numberOfThreads << " THREADS" << endl << endl;
    }
    else 
    {
        cout << "START WITH 5 THREADS" << endl << endl;
    }

    for(int i = 0; i < numberOfThreads; i++)
    {
        threads.push_back(thread(&Philosopher::Do, Philosopher(i)));
    }

    for(auto &t :threads)
    {
        if(t.joinable())
        {
            t.join();
        }
    }

    return 0;
}