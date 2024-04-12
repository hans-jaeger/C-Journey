/*

Created by: Hans Jaeger
Created on: 2024/04/11
Description:  The Demo Program for Ship
Note: The professor has given me permission to program in C++.

*/

#include <iostream>
#include "Ship.h"
#include "CruiseShip.h"
#include "CargoShip.h"

using namespace std;

int main()
{

    // Declaring that size of the array won't change
    const int arraySize = 3;

    Ship *shipArray[arraySize];

    shipArray[0] = new Ship("SS-Milno", "1850");
    shipArray[1] = new CruiseShip("SS-Runner", "1853", 150);
    shipArray[2] = new CargoShip("SS-Leslie", "1870", 10);

    // Formatting:
    cout << endl;
    // Display ship information
    for (int i = 0; i < arraySize; i++)
    {
        cout << shipArray[i]->toString() << endl;
    }

    // Clean up dynamically allocated memory
    for (int i = 0; i < arraySize; i++)
    {
        delete shipArray[i];
    }

    return 0;
}
