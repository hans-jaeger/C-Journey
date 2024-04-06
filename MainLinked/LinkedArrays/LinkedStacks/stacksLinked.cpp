
#include <iostream>

using namespace std;

class stacksLinked
{
private:
    class Node
    {
    public:
        int data;
        Node *next;
    };
    int stackSize;
    int top;
    Node **stackArray;
    Node *head = nullptr;
    Node *tail = nullptr;

public:
    // Constructor
    stacksLinked(int size)
    {
        stackSize = size;
        stackArray = new Node *[stackSize];
        top = -1;
    }
    stacksLinked(int size, int nodes)
    {
        stackSize = size;
        stackArray = new Node *[stackSize];
        top = -1;
        while (nodes != 0)
        {
            addNode();
            nodes--;
        }
    }
    // Operations:
    void addNode()
    {
        // Creation of new Node;
        Node *newNode = new Node();
        if (top < stackSize - 1) // Check if stack is not full
        {
            cout << "What is the data?\n";
            cin >> newNode->data;
            if (head)
            {
                tail->next = newNode;
                tail = newNode;
            }
            else
            {
                head = newNode;
                tail = newNode;
            }
            top++;
            stackArray[top] = newNode;
        }
        else
        {
            cout << "Stack is full\n";
        }
    };
    void dislay()
    {
        cout << "Displaying Content of the stackLinked List\n";
        Node *temp;
        while (top != -1)
        {
            temp = stackArray[top];
            cout << temp->data << endl;
            top--;
        }
    }
    bool isEmpty()
    {
        return head == nullptr;
    }
};

int main()
{
    stacksLinked firstConstructor(3, 3);
    firstConstructor.dislay();
}
