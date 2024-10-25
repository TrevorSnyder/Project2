#include "LinkedList.h"

#ifndef TASK_H
#define TASK_H

#include <iostream>

using namespace std;


class Task
{
    private: 
        string taskName;
        bool urgentcy;
        int time;

    public:
        Task() {};
        Task(string n, bool u, int t);

};

Task::Task(string n, bool u, int t)
{
    this->taskName = n;
    this->urgentcy = u;
    this->time = t;
}



#endif