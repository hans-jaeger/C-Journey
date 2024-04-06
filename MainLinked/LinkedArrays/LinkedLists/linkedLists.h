/*
Author: Hans Jaeger
Date: Feb 22, 2024
File: linkedLists.h
*/
#ifndef LINKEDLISTS_h
#define LINKEDLISTS_h

#include <string>

using namespace std;
class linkedLists
{
private:
    // Set up for Node
    struct Node
    {
        string data;
        struct Node *next;
        // Constructor set instead of calling a sister constructor.
        Node(string val, Node *n = nullptr)
        {
            data = val;
            next = n;
        };
    };
    // Pointers`
    Node *head;
    Node *tail;
    int counter;

public:
    // Constructor: Make sure to be public since we want to call outside of the class.
    linkedLists()
    {
        head = nullptr;
        tail = nullptr;
    };
    // Operations
    void add(string data);
    void add(int, string);
    void eliminate(int);
    void eliminate(string);
    string toString();
    void displaylist();
    void getTail();
    bool isEmpty();
    int size();
};

#endif
