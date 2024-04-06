/*
Author: Hans Jaeger
Date: Feb 28, 2024
File: linkedLists.cpp

Description:
This file contains the implementation of a linked list data structure in C++. It provides functions to add nodes, display the list, eliminate nodes, and retrieve information about the list.

Usage:
1. To add a node to the linked list, use the `add` void function. There are two versions of this function: one to add a node at the end of the list, and another to add a node at a specific index.
2. To display the entire linked list, use the `displaylist` void function.
3. To convert the linked list data into a string, use the `toString` string function.
4. To eliminate a node from the linked list, use the `eliminate` function. There are two versions of this function: one to eliminate a node based on the index, and another to eliminate a node based on the data.
5. To retrieve the value of the tail node, use the `getTail` void function.
6. To check if the linked list is empty, use the `isEmpty` boolean function.
7. To get the size of the linked list, use the `size` int function.

Note: This implementation assumes a singly linked list structure, where each node has a data and an address to the next Node.

Thank you for using my program :)
*/

#include <iostream>
#include "linkedLists.h"
#include <string>
// This library is used for streamstring class
#include <sstream>

using namespace std;
/*
Description: Adds a node to a linked list
*/
void linkedLists::add(string data)
{
    // Creation of node
    Node *newNode = new Node(data);

    // If this is the first node, then make both pointers point at the same node
    if (!head)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        // Set the last element within the list to the newNode and then re-assign the tail to newNode;
        tail->next = newNode;
        tail = newNode;
    }
}
/*
Description: Adds a node based on the index and data. Same principle as the above function but with a different signature
*/
void linkedLists::add(int index, string data)
{
    // New Node
    Node *newNode = new Node(data);
    // Temp Node
    Node *tracker = head;
    // Replacing head
    if (index == 0)
    {

        newNode->next = head->next->next;
        head = newNode;
        if (tail == nullptr)
        {
            tail = newNode;
        }
    }
    // Check whether the index is within bounds since we are using custom index values
    else if (index == -1 || index > size())
    {
        throw out_of_range("Out of bounds");
    }
    // Insertion for regular modes:
    for (int i = 0; i < index - 1; i++)
    {
        tracker = tracker->next;
    }
    // Once we have stopped at the correct index: Assign the New Node->next to the tracker node next since this will be in front of the newNode.
    newNode->next = tracker->next;
    // Set the current node tracker to link to the newNode from behind.
    tracker->next = newNode;
    // Updating tail value since we are adding a new value
    if (tracker->next->next == NULL)
    {
        tail = tracker->next;
    }
}
/*
Description: This function displays the entire linked list
*/
void linkedLists::displaylist()
{
    Node *tempNode = head;
    while (tempNode != nullptr)
    {
        cout << tempNode->data << "\n";
        tempNode = tempNode->next;
    }
}
/*
Description: This function creates an object from the stringstream class and transforms the linked list data into string content. This class is the equivalent to StrBuilder from Java.
*/
string linkedLists::toString()
{

    stringstream strBuilder;
    Node *p = head;
    while (p != nullptr)
    {
        strBuilder << p->data << ", ";
        p = p->next;
    }
    return strBuilder.str();
}
/*
Description: The eliminate function eliminates a Node from the linked list based on the index. For example, if the user inputs index 1 then the function eliminates the node at index 1 and connects the address from the previous node to the previous node next address.
*/
void linkedLists::eliminate(int index)
{

    // Assign node to head as that is the only reference we need to make
    Node *tempNode = head;
    // If the index is referring to the head
    if (index == 1)
    {

        // If the list is empty
        if (head == nullptr)
        {
            cout << "Nothing to eliminate";
        }
        else
        {
            // make the new head the next one
            head = head->next;
        }
        return;
    }
    // If the index is referring to the tail through -1 or by a positive index, we can refer to the size function.
    if (index == -1 || index == size())
    {

        if (head == tail)
        {
            cout << "Nothing to eliminate";
        }
        else
        {
            // Travel through the linked list since we do not have the back address for a single linked list
            while (tempNode->next != tail)
            {
                // Travel through each node
                tempNode = tempNode->next;
            }
            // The tempNode currently holds the node before the tail. We re-assign the tail to the tempNode.
            tail = tempNode;
            // Set the tail next to nullptr.
            tail->next = nullptr;
        }
        return;
    }
    if (index > size() || index < -1)
    {
        cout << "Elimination Function:\n";
        throw out_of_range("Out of bounds");
    }
    // Index Specific Elimination:

    for (int i = 0; i < index - 1; i++)
    {
        tempNode = tempNode->next;
    }
    if (tempNode != nullptr)
    {
        // Create a node that points to the eliminated Node
        Node *eliminatedNode = tempNode->next;
        // Set the eliminated node pointer next to the next pointer for the tempNode
        tempNode->next = eliminatedNode->next;
        if (eliminatedNode->next == tail)
        {
            tail = tempNode;
        }
        free(eliminatedNode);
        return;
    }
}
/*
Description: Instead of index based elimination, we focus on the string data elimination
*/
void linkedLists::eliminate(string data)
{
    Node *predNode = head;
    //

    while (!isEmpty() && predNode->next->data != data && predNode->next->next != nullptr)
    {
        predNode = predNode->next;
    }
    // predNode is pred to the data matched
    if (predNode->next->data == data)
    {
        if (predNode->next == tail)
        {
            tail = predNode;
            tail->next = nullptr;
            return;
        }
        else
        {
            // Changes the pred address to one that the eliminated node had.
            predNode->next = predNode->next->next;
        }
    }
    else
    {
        cout << "\nEither Data does not exist or the list is empty\n";
    }
}
/*
Description: The function returns the tail value;
*/
void linkedLists::getTail()
{
    if (tail != nullptr)
    {
        cout << "The tail value of the list is: " << tail->data << "\n";
    }
    else if (tail == head)
    {
        cout << "The list is empty\n";
    }
}
/*
Description: The function testes if the head is assigned to a node, if not then it will return true
*/
bool linkedLists::isEmpty()
{
    return head == NULL;
}
/*
Description: The function counts the amount of nodes within the linked list by using a counter to increment each time we pass through a node.
*/
int linkedLists::size()
{
    Node *tempNode = head;
    counter = 0;
    while (tempNode != NULL)
    {

        tempNode = tempNode->next;
        counter += 1;
    }

    return counter;
}