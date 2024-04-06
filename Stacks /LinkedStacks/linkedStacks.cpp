#include <iostream>
#include "linkedStacks.h"

using namespace std;

void linkedStack::push(int value)
{
    if (isEmpty())
    {
        // Assign a new top
        top = new Node(value);
    }
    else
    {
        top = new Node(value, top);
    }
}

void linkedStack::pop()
{
    if (!isEmpty())
    {
        Node *temp = top;
        top = top->next;
        delete temp;
    }
    else
    {
        cout << "Cannot Eliminate: The stack is empty\n";
    }
}
void linkedStack::display()
{
    Node *temp = top;
    while (temp != nullptr)
    {
        cout << temp->data << endl;
        temp = temp->next;
    }
}
void linkedStack::peek()
{
    if (isEmpty())
    {
        cout << "The stack is empty\n";
    }
    else
    {
        cout << "The top value is: " << top->data << endl;
    }
}
bool linkedStack::isEmpty()
{
    return top == nullptr;
}