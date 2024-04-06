#include <iostream>
#include "stacks.h"

stacks::stacks(int size)
{
    stackArray = new int[size];
    stackSize = size;
    top = -1;
}
void stacks::push(int num)
{
    if (top == stackSize - 1)
    {
        std::cout << "Stack is full\n";
    }
    else
    {
        top++;
        stackArray[top] = num;
        std::cout << "Successful Push" << std::endl;
    }
}

void stacks::pop(int &num)
{
    if (top == -1)
    {
        std::cout << "Stacks is already empty\n";
    }
    else
    {
        num = stackArray[top];
        top--;
    }
}

void stacks::display()
{
    for (int i = 0; i < stackSize; i++)
    {
        std::cout << stackArray[i] << std::endl;
    };
}

bool stacks::isEmpty() const
{
    return top == -1;
}
bool stacks::isFull() const
{
    return top != -1;
}

void stacks::peek()
{
    if (isEmpty())
    {
        std::cout << "The stack is empty";
    }
    else
    {
        std::cout << "The top element in the stack is: " << stackArray[top] << std::endl;
    }
}