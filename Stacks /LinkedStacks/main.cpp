/*
Author: Hans Jaeger
Date: March 1, 2024
*/

#include <iostream>
#include "linkedStacks.h"

using namespace std;

int main()
{
    linkedStack stackLinked;
    stackLinked.push(10);
    stackLinked.push(50);
    stackLinked.push(30);
    stackLinked.peek();
    stackLinked.display();
}
