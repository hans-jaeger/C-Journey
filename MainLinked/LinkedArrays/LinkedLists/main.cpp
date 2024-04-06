/*
Author: Hans Jaeger
Date: Feb 22, 2024
File: main.cpp
*/

#include <iostream>
#include "linkedLists.h"

using namespace std;

int main()
{
    // Variable Declaration
    int counter;
    string stringList;
    // Create object
    linkedLists list;
    // Call Operations
    list.add("Hello");
    list.add("Nevermind");
    list.add("NOOO");
    list.add("Leslie");
    list.add("Fourty");
    list.add("EliminatedTarget");
    list.add(1, "InsertedSection");
    list.displaylist();
    list.getTail();
    list.eliminate("NOOO");
    //-1 calls the tail value
    list.eliminate(-1);
    list.displaylist();
    // Store the return of the function size()
    counter = list.size();
    cout << "The amount of elements within the linked list are: " << counter;
    // Using toString function section:
    stringList = list.toString();
    cout << "\nHere is the formatted string list\n";
    cout << stringList;
}