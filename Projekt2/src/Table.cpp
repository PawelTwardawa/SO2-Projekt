#include "Table.hpp"

Table::Table(int count)
{
    //forks.

    //forks = 
    //forks.resize(count);
    for(int i = 0; i < count; i++)
    {
        Fork *fork = new Fork();
        forks.push_back(fork);
    }
};

Table::Table()
{

};