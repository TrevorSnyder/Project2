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
        Task() {}

        Task(string n, bool u, int t)
        {
            this->taskName = n;
            this->urgentcy = u;
            this->time = t;
        }

        friend ostream & operator << (ostream & os, Task t)
        {
            os << "\nTask Name: " << t.taskName;

            os << "\nUrgency: ";
            if(t.urgentcy == true)
            {
                os << "Urgent\n";
            }
            else
            {
                os << "Not Urgent\n";
            }

            os << "Task Completion Time: " << t.time << "min" << endl;

            return os;
        }

        bool operator !=(const Task& t)
        {
            if(this->taskName != t.taskName)
            {
                return true;
            }
            else
            {
                return false;
            }
        }

        bool operator==(const Task& t)
        {
            if(this->taskName == t.taskName)
            {
                return true;
            }
            else
            {
                return false;
            }
        }

        bool operator<(const Task& t)
        {
            if(this->time < t.time)
            {
                return true;
            }
            else
            {
                return false;
            }
        }

        Task addTask()
        {
            string nameOfTask;
            char urgentChar;
            int taskCompletionTime;
            bool urgentcy;

            cin.ignore();
            cout << "Task Name: ";
            getline(cin, nameOfTask);

            cout << "Is the task urgernt(y/n): ";
            cin >> urgentChar;

            cout << "Task Completion Time (mins) - Enter Positive Integer: ";
            cin >> taskCompletionTime;

            if(urgentChar == 'y')
            {
                urgentcy = true;
            }
            if(urgentChar == 'n')
            {
                urgentcy = false;
            }

            Task newTask = Task(nameOfTask,urgentcy,taskCompletionTime);
            return newTask;
        }
};



#endif