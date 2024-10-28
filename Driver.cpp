#include <iostream>
#include <cctype>
#include <limits>
#include "LinkedList.h"
#include "LinkedList.cpp"
#include "Task.h"
#include <string>

using namespace std;

int main()
{
    int choice;
    int choice2;
    int removeChoice;
    bool urgentcyBool;

    LinkedList<Task> myList;

    //menu that uses do-while loop to run as long as user desires
    do
    {
        cout << "\n\n*** TO DO LIST ***" << endl;
        cout << "\n What would you like to do?" << endl;
        cout << "1.) Add a task" << endl;
        cout << "2.) Remove a task" << endl;
        cout << "3.) Show all task" << endl;
        cout << "4.) End Program and Clear All Tasks" << endl;
        cout << "Choose 1 - 4: ";

        while(!(cin >> choice) || (choice < 1) || (choice > 4)) //ensures user selects proper menu option and that option is valid
        {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "\nYou did not enter a valid choice.\n";
            cout << "\nCHOOSE 1-4: \n";
            
        }

        switch(choice)
        {
            case 1:
            {
                //user prompt to select where task should go
                cout << "\nWhere would you like to add the task?" << endl;
                cout << "1.) The end of the list" << endl;
                cout << "2.) A specific postion" << endl;
                cout << "Enter choice: ";
                cin >> choice2;
                
                //creates a new task (like the name suggests) with addTask() function 
                Task newTask = newTask.addTask();

                //if else handles which option is selected
                if(choice2 == 1)
                {
                    myList.appendNode(newTask); //adds to end of list
                }

                else if(choice2 == 2)
                {
                   int position;
                   cout << "Enter a specific section for your task: ";
                   cin >> position;
                   myList.insertAtPosition(newTask, position); //does as the selection says, adds user task at selected position
                }

                else
                {
                    cout << "Invalid input! Choose 1 or 2"; //checks for correct input
                }
            }
            break;

            case 2:
            {
               cout << "Enter the position of the task you want removed: \n";
               cin >> removeChoice;
               myList.deleteNodeAtPosition(removeChoice);
            }
            break;

            case 3:
            {   
                //display tasks
                cout << "Printing all tasks:\n\n";
                myList.displayList();
            }
            break;

            case 4:
            {
                //End program and print message for clearing all tasks
                cout << "\nClearing tasks\n";
            }
            break;
        }



    }while(choice != 4);






    return 0;
}