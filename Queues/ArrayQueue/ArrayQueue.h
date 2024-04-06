/*
Author: Hans Jaeger
Date: March 2, 2024
*/

#ifndef ARRAYQUEUE_H
#define ARRAYQUEUE_H

#include <iostream>

using namespace std;

template <class T>
class arrayQueue
{
private:
    T *array;
    int arraySize;
    int front;
    int last;

public:
    // Constructor
    arrayQueue(int);

    // Opertaions:
    void enqueue(T);
    bool isEmpty();
    bool isFull();
    void dequeue();
    void peak();
    void display();
};

// Definitions:
template <class T>
arrayQueue<T>::arrayQueue(int size)
{
    if (size > 0)
    {
        arraySize = size;
        array = new T[arraySize];
        front = -1;
        last = 0;
    }
    else
    {
        cout << "Stack Size cannot be negative ";
    }
}
template <class T>
bool arrayQueue<T>::isEmpty()
{
    return front == -1;
}
template <class T>
void arrayQueue<T>::enqueue(T data)
{
    if (last < arraySize - 1)
    {
        if (front == -1)
        {
            front++;
            array[front] = data;
        }
        else
        {
            last = (last + 1) % arraySize;
            array[last] = data;
        }
    }
}
template <class T>
void arrayQueue<T>::dequeue()
{
    if (isEmpty())
    {
        cout << "The queue is already empty";
    }
    else
    {
        front = (front + 1) % arraySize;
    }
}
template <class T>
void arrayQueue<T>::display()
{
    if (isEmpty())
    {
        cout << "The queue is empty" << endl;
    }
    else
    {
        int current = front;
        while (current != last)
        {
            cout << array[current] << endl;
            current = (current + 1) % arraySize;
        }
        cout << array[last] << endl;
    }
}
#endif