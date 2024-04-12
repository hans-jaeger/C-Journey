/*

Created by: Hans Jaeger
Created on: 2024/04/11
Description: The following is the creation of the Ship Class which we call into an array in the main program.

*/
#ifndef SHIP_CLASS_H
#define SHIP_CLASS_H
#include <iostream>
#include <string>

using namespace std;

class Ship
{
private:
    string name;
    string year;

public:
    // Constructors

    // This constructor initializes the 'name' and 'year' member variables efficiently
    // by using an initializer list. This approach is preferred for performance.

    // The use of 'const' in the constructor parameters ensures that we can accept
    // string literals as arguments. In C++, non-const references cannot bind to
    // temporary objects like string literals.

    // Alternatively, we could use non-const references, but that would require passing
    // string objects as arguments instead of string literals, which may be less flexible.

    /* Further Explanation:
    // Here is an example of creating a string object:
    string newName = "Wolfer";
    // The "Hello" is a string literal, which is implicitly converted to a const char*. The const char* derives from the reference capability.
    // This conversion occurs because string literals are arrays of constant characters (const char[]).
    random_function("Hello")
    */
    Ship(const string &newName, const string &newYears) : name(newName), year(newYears)
    {
    }

    // Setters and Mutators
    void setShipName(string newName)
    {
        this->name = newName;
    }

    void setYearBuilt(string newYear)
    {
        this->year = newYear;
    }

    // Accessors
    string getShipName() const
    {
        return name;
    }

    string getYearBuilt() const
    {
        return year;
    }
    // This function is declared virtual because we are creating an array of Ships.
    // Without virtual, the compiler would only consider this class's version of the function, ignoring any overrides in derived classes.
    // This dynamic resolution of the function call based on the object's actual type at runtime is known as Dynamic Binding, as opposed to Static Binding, which relies on the type of the pointer or reference used to call the function.

    virtual string toString() const
    {
        return ("Ship " + this->name + " - Built: " + this->year + "\n");
    }
};

#endif