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
    int counter = 1;

    while(ptr)
    {
        cout << "Deleting Task " << counter << endl;
        delete ptr;
        ptr = ptr->next;
        counter++;
    }
}

template <typename T>
void LinkedList<T>::appendNode(T value1)
{
    ListNode* newNode = new ListNode(value1);
    if(head == NULL)
    {
        head = newNode;
        return;
    }

    ListNode* tempPtr = head;
    while(tempPtr->next != NULL)
    {
        tempPtr = tempPtr->next;
    }

    tempPtr->next = newNode;
}

template <typename T>
void LinkedList<T>::insertAtPosition(T value1, int position)
{
    if(position < 1)
    {
        cout << "\nInvalid Position" << endl;
        return;
    }

    ListNode* ptr = new ListNode(value1);

    if(position == 1)
    {
        ptr->next = head;
        head = ptr;
        if (tail == NULL)
        {
            tail = ptr;
        }
        return;
    }

    ListNode* ptr2 = head;
    int currentPosition = 1;

    while (ptr2 != NULL && currentPosition < position - 1)
    {
        ptr2 = ptr2->next;
        currentPosition++;
    }
    
    if(ptr2 == NULL)
    {
        delete ptr;
        return;
    }

    ptr->next = ptr2->next;
    ptr2->next = ptr;

    if(ptr->next == NULL)
    {
        tail = ptr;
    }
}

template <typename T>
void LinkedList<T>::prependNode(T value1)
{
    ListNode* ptr =  new ListNode();
    ptr->value = value1;
    ptr->next = head;
    head = ptr;
    return;
}

template <typename T>
void LinkedList<T>::deleteNodeAtPosition(int position)
{
    if(head == NULL)
    {
        cout << "The list is empty. Cannot delete from an empty list." << endl;
        return;
    }

    if(position < 1)
    {
        cout << "Position must be greater than or equal to 0";
    }


    if(position == 1)
    {
        ListNode* ptr = new ListNode();
        ptr = head;
        head = head->next;
        delete ptr;
        return;
    }

    ListNode* ptr2 = new ListNode();
    ptr2 = head;

    while(position-- > 1)
    {
        ptr2 = ptr2->next;
        position--;
    }

    ListNode* ptr3 = new ListNode();
    ptr3 = ptr2->next;
    ptr2->next = ptr3->next;
    delete ptr3;
    return;


}

template<typename T>
void LinkedList<T>::displayList() const
{
    ListNode* ptr = new ListNode();
	ptr = head;

	int number = 1;
	while(ptr)
	{
		
		cout << "--Task " << number;
		cout << ptr->value << endl;
		ptr = ptr->next;
		number++;
	}
}

template<typename T>
void LinkedList<T>::sortList()
{
    if (!head || !head->next) //case if list is empty/has 1 element
    {
        return;
    }

    quickSort(head, nullptr); //sorting starts at head
}

template<typename T>
void LinkedList<T>::quickSort(ListNode* low, ListNode* high)
{
    if (low != high)
    {
        ListNode* pivotNode = partition(low, high);
        quickSort(low, pivotNode); 
        if (pivotNode != nullptr && pivotNode->next != nullptr)
        {
            quickSort(pivotNode->next, high);
        }
    }
}

template<typename T>
typename LinkedList<T>::ListNode* LinkedList<T>::partition(ListNode* low, ListNode* high)
{
    T pivot = low->value; //first node used as pivot
    ListNode* i = low;
    ListNode* h = low->next;

    while (h != high)
    {
        if (h->value < pivot)
        {
            i = i->next;
            swap(i->value, h->value);
        }
        
        h = h->next;
    }
    swap(low->value, i->value);
    return i;
}