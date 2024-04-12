/*

Created by: Hans Jaeger
Created on: 2024/04/11
Description:

*/
#ifndef CRUISE_SHIP_CLASS_H
#define CRUISE_SHIP_CLASS_H
#include <iostream>
#include "Ship.h"

class CruiseShip : public Ship
{
private:
    int maxPassengers;

public:
    // Constructors
    CruiseShip(const string &newName, const string &newYear, const int &newMaxPassengers) : Ship(newName, newYear), maxPassengers(newMaxPassengers)
    {
    }

    // Mutators
    void setNumPassengers(int newMaxPassengers)
    {
        this->maxPassengers = newMaxPassengers;
    }

    // Accessors
    int getNumPassengers() const
    {
        return this->maxPassengers;
    }

        virtual string toString() const override
    {
        return ("Cruise Ship: " + getShipName() + " - #Passengers: " + to_string(this->maxPassengers) + "\n");
    }
};

#endif
