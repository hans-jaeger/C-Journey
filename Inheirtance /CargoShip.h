/*
Author: Hans Jaeger
Date: April 11, 2024
Description: Class for the CargoShip which inherits from the Ship class.
*/
#ifndef CARGO_SHIP_CLASS_H
#define CARGO_SHIP_CLASS_H
#include <iostream>
#include "Ship.h"

class CargoShip : public Ship
{
private:
    int tonnage;

public:
    // Constructors
    CargoShip(const string &newName, const string &newYear, const int &newTonnage) : Ship(newName, newYear), tonnage(newTonnage)
    {
    }

    // Mutators
    void setCargoCapacity(int newTonnage)
    {
        this->tonnage = newTonnage;
    }

    // Accessors
    int getCargoCapacity() const
    {
        return this->tonnage;
    }

    virtual string toString() const override
    {
        return ("Cargo Ship: " + getShipName() + " - Tonnage: " + to_string(tonnage) + "\n");
    }
};

#endif