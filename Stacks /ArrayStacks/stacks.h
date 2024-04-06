#ifndef STACKS_h
#define STACKS_h

class stacks
{
private:
    // Declare Variables:
    int *stackArray;
    int stackSize;
    int top;

public:
    // Constructor
    stacks(int);
    // Operations
    void push(int);
    void pop(int &);
    void peek();
    void display();
    bool isFull() const;
    bool isEmpty() const;
};

#endif