#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
using namespace std;

template <typename T>
class LinkedList
{
    public:
        LinkedList();
        ~LinkedList();
        void appendNode(T value);
        void insertAtPosition(T value, int position);
        void prependNode(T value);
        void deleteNodeAtPosition(int position);
        void displayList() const;
        void sortList();

        

    private:
        struct ListNode
        {
            T value;
            ListNode* next;
            ListNode(const T e = T(), ListNode* n = NULL) : value(e), next(n) {}
        };

        ListNode* head;
        ListNode* tail;
        void quickSort(ListNode* low, ListNode* high);
        ListNode* partition(ListNode* low, ListNode* high);
};



#endif 