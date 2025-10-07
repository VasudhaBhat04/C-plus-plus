/*
Abstraction --> Hiding all unnecessary detailes & showing only important parts
Achieved using:-
access modifiers/specifiers
using abstarct class
pure virtual functions

Abstract Class
A class that cannot be instantiated.You cannot create an object of that class directly.
Must contain at least one pure virtual function.

Pure Virtual Function
Declared using = 0.
Must be overridden in derived class.

SYNTAX:
class AbstractClass {
public:
    virtual void display() = 0; // pure virtual function
};

*/

#include <iostream>
using namespace std;

// Abstract class
class Shape {
public:
    virtual void area() = 0;  // pure virtual function
};

// Derived class 1
class Circle : public Shape {
    float radius;
public:
    Circle(float r) : radius(r) {}
    void area() override {
        cout << "Area of Circle: " << 3.14 * radius * radius << endl;
    }
};

// Derived class 2
class Rectangle : public Shape {
    float length, width;
public:
    Rectangle(float l, float w) : length(l), width(w) {}
    void area() override {
        cout << "Area of Rectangle: " << length * width << endl;
    }
};

int main() {
    Shape* s1 = new Circle(5); //Gotta do dynamic allocation
    Shape* s2 = new Rectangle(4, 6);
    // Shape s;  // Error: cannot instantiate abstract class

    s1->area(); // Calls Circle's area
    s2->area(); // Calls Rectangle's area

    delete s1;
    delete s2;
}

/* 
Object creation
Static allocation (Stack)

classname objectname;
classname.objectname="";
objectname.function();

Eg:
Circle c1(5);  // Static allocation
c1.area();

Dynamic allocation (Heap)

ClassName* pointerName = new ClassName(arguments);
pointerName->function()
delete pointerName;   // Important to avoid memory leak

Shape* s1 = new Circle(5);  // Dynamic object
s1->area();                  // Call
delete s1;                   // Free heap memory

*/
