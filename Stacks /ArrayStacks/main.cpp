#include <iostream>
#include "stacks.h"

using namespace std;

int main()
{
    stacks arrayStacks(5);
    arrayStacks.push(12);
    arrayStacks.push(3);
    arrayStacks.push(90);
    arrayStacks.push(2);
    arrayStacks.push(5);
    arrayStacks.peek();
    arrayStacks.display();
}