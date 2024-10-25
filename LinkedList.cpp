#include "LinkedList.h"

#include <iostream>
using namespace std;


template <typename T>
LinkedList<T>::LinkedList()
{
    head = NULL;
    tail = NULL;
}

template <typename T>
LinkedList<T>::~LinkedList()
{
    ListNode* ptr = new ListNode();
    ptr = head;

    while(ptr)
    {
        delete ptr;
        ptr = ptr->next;
    }
}

template <typename T>
void LinkedList<T>::appendNode(T value)
{
    ListNode* newNode = new ListNode(value);
    if(head == NULL)
    {
        head = newNode;
    }

    ListNode* tmp = head;
    while(tmp->next != NULL)
    {
        tmp = tmp->next;
    }

    tmp->next = newNode;
}

template <typename T>
void LinkedList<T>::insertAtPosition(T value1, int position)
{
    if(position < 1)
    {
        cout << "Invalid Position" << endl;
        return;
    }

    if(position == 1)
    {
        ListNode* ptr = new ListNode();
        ptr->value = value1;
        ptr->next = head;
        return;
    }

    ListNode* ptr2 = new ListNode();
    ptr2 = head;

    ListNode* ptr3 = new ListNode();
    ptr3->value = value1;
    ptr3->next = NULL;

    while(--position > 1)
    {
        ptr2 = ptr2->next;
    }

    ptr3->next = ptr2->next;
    ptr2->next = ptr3;

    return;
}

