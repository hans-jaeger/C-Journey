#ifndef LINKEDSTACKS_H
#define LINKEDSTACKS_H
#include <iostream>

using namespace std;

class linkedStack
{
private:
    class Node
    {
    public:
        int data;
        Node *next;
        // Constructor
        Node(int value, Node *n = nullptr)
        {
            data = value;
            next = n;
        }
    };
    Node *top;

public:
    // Constructors:
    linkedStack()
    {
        // Setting the pointer to empty
        top = nullptr;
    }
    void push(int);
    void pop();
    void display();
    void peek();
    bool isEmpty();
};
#endif