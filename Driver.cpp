#include <iostream>
#include "LinkedList.h"
#include "Task.h"

using namespace std;

int main()
{
    int choice;
    int choice2;
    int maxSize;
    int removeChoice;

    LinkedList<Task> myList;

    cout << "What is the maximum size of your list?" << endl;
    cin >> maxSize;

    do
    {
        cout << "\n\n*** TO DO LIST ***" << endl;
        cout << "\n What would you like to do?" << endl;
        cout << "1.) Add a task" << endl;
        cout << "2.) Remove a task" << endl;
        cout << "3.) Show all task" << endl;
        cout << "4.) End Program and Clear All Tasks" << endl;
        cout << "Choose 1 - 4: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
            {
                cout << "Where would you like to add the task?" << endl;
                cout << "1.) The end of the list" << endl;
                cout << "2.) A specific postion" << endl;
                cout << "Enter choice: ";
                cin >> choice2;

                if(choice2 == 1)
                {
                   
                }

                if(choice2 == 2)
                {
                   
                }
            }
            break;

            case 2:
            {
               
            }
            break;

            case 3:
            {
               
            }
        }



    }while(choice != 4);






    return 0;
}