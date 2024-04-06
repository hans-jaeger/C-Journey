/*
Author: Hans Jaeger
Date: March 2, 2024

*/

#include <iostream>
#include <string>
#include "ArrayQueue.h"

using namespace std;

int main()
{
    arrayQueue<string> nameQueue(4);
    nameQueue.enqueue("Hello");
    nameQueue.enqueue("Lorsh");
    nameQueue.dequeue();
    nameQueue.display();
}
