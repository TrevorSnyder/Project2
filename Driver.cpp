/*
Program 2: To-Do List
Authors: Trevor Snyder & Adam Campbell
Due: 11/01/24

******PLEASE READ THIS******
Trevor wasn't able to upload changes to github, so he emailed me
his stuff, I reworked some code or added new things and uploaded that
to project 2 repo
- Adam
*/


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
    int listChoice;

    LinkedList<Task> myList;

    //menu that uses do-while loop to run as long as user desires
    do
    {
        cout << "\n\n*** TO DO LIST ***" << endl;
        cout << "\n What would you like to do?" << endl;
        cout << "1.) Add a task" << endl;
        cout << "2.) Remove a task" << endl;
        cout << "3.) Show all task" << endl;
        cout << "4.) Load Basic To-Do List" << endl;
        cout << "5.) Sort Tasks by Time" << endl;
        cout << "6.) End Program and Clear All Tasks" << endl;
        cout << "Choose 1 - 6: ";

        while(!(cin >> choice) || (choice < 1) || (choice > 6)) //ensures user selects proper menu option and that option is valid
        {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "\nYou did not enter a valid choice.\n";
            cout << "\nCHOOSE 1-6: \n";
            
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
                   cout << "Position for task (1,2,3...): ";
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
               cout << "\nEnter the position of the task you want removed: ";
               cin >> removeChoice;
              
               myList.deleteNodeAtPosition(removeChoice);

               cout << "Task removed! \n";
            
            }
            break;

            case 3:
            {   
                //display tasks
                cout << "\nPrinting all tasks:\n\n";
                myList.displayList();
            }
            break;

            case 4:
            {
                cout << "\nWhich To-Do List do you want to load and add?" << endl;
                cout << "1.) Home Cleaning" << endl;
                cout << "2.) Yard Work" << endl;
                cout << "3.) Body Improvement" << endl;
                cout << "4.) Finances" << endl;
                cout << "5.) Mix of all above" << endl;
                cout << "Choice: ";
                cin >> listChoice;

                if(listChoice == 1)
                {
                    Task list1("Wash Dishes", true, 30);
                    myList.appendNode(list1);
                    Task list2("Do laundry", true, 60);
                    myList.appendNode(list2);
                    Task list3("Vacuum/Mop", true, 45);
                    myList.appendNode(list3);
                    Task list4("Take out garbage", true, 5);
                    myList.appendNode(list4);
                    Task list5("Dust Home", true, 20);
                    myList.appendNode(list5);
                }
                if(listChoice == 2)
                {
                    Task list6("Mow yard", true, 60);
                    myList.appendNode(list6);
                    Task list7("Trim bushes/trees", true, 60);
                    myList.appendNode(list7);
                    Task list8("Powerwash driveway/house", true, 120);
                    myList.appendNode(list8);
                }
                if(listChoice == 3)
                {
                    Task list9("Do yoga/stretch", true, 15);
                    myList.appendNode(list9);
                    Task list10("Do cardio", true, 30);
                    myList.appendNode(list10);
                    Task list11("Do strength training", true, 30);
                    myList.appendNode(list11);
                    Task list12("Meditate", true, 10);
                    myList.appendNode(list12);
                }
                if(listChoice == 4)
                {
                    Task list13("Budget Paycheck", true, 45);
                    myList.appendNode(list13);
                    Task list14("Pay Off Debt", true, 60);
                    myList.appendNode(list14);
                    Task list15("Create Savings Account", true, 60);
                    myList.appendNode(list15);
                }
                if(listChoice == 5)
                {
                    Task list16("Wash Dishes", true, 30);
                    myList.appendNode(list16);
                    Task list17("Take Out Garbage", true, 5);
                    myList.appendNode(list17);
                    Task list18("Mow Yard", true, 60);
                    myList.appendNode(list18);
                    Task list19("Do Cardio", true, 30);
                    myList.appendNode(list19);
                    Task list20("Budget Paycheck", true, 45);
                    myList.appendNode(list20);
                }

                if(listChoice < 1 || listChoice > 5)
                {
                    cout << "Error! Invalid Input" << endl;
                }
            }
            break;

            case 5:
            {
                cout << "\nSorting tasks based on estimated time...\n";
                myList.sortList();
                cout << "Your tasks should now be sorted by time\n";
            }
            break;

        }



    }while(choice != 6);

    cout << "\nClearing tasks:\n";
    myList.~LinkedList();


    

    return 0;
}