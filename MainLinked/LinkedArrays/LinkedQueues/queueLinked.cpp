#include <iostream>
#include <string>

using namespace std;

// Node class for the linked list
class Node
{
public:
    string data; // Data stored in the node
    Node *next;  // Pointer to the next node

    // Constructor
    Node(string data) : data(data), next(nullptr) {}
};

// Queue Linked List class
class QueueLinkedList
{
private:
    Node *head; // Pointer to the first node (front of the queue)
    Node *tail; // Pointer to the last node (end of the queue)
public:
    // Constructor
    QueueLinkedList() : head(nullptr), tail(nullptr) {}

    // Destructor to free memory
    ~QueueLinkedList()
    {
        while (head != nullptr)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
        }
    }

    // Adds a node to the end of the queue
    void enqueue(string data)
    {
        Node *newNode = new Node(data);
        if (isEmpty())
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

    // Removes and returns the front element of the queue
    string dequeue()
    {
        if (isEmpty())
        {
            throw out_of_range("Queue is empty");
        }
        string data = head->data;
        Node *temp = head;
        head = head->next;
        delete temp;
        if (head == nullptr)
        {
            tail = nullptr;
        }
        return data;
    }

    // Checks if the queue is empty
    bool isEmpty()
    {
        return head == nullptr;
    }

    // Displays the elements of the queue
    void displayQueue()
    {
        Node *current = head;
        while (current != nullptr)
        {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main()
{
    // Create a queue linked list object
    QueueLinkedList queue;

    // Enqueue some elements
    queue.enqueue("Hello");
    queue.enqueue("World");
    queue.enqueue("!");

    // Display the queue
    cout << "Queue elements: ";
    queue.displayQueue();

    // Dequeue an element
    cout << "Dequeued element: " << queue.dequeue() << endl;

    // Display the queue after dequeue
    cout << "Queue elements after dequeue: ";
    queue.displayQueue();

    return 0;
}
