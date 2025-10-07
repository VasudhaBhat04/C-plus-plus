/*Polymorphism-ability of objects to take on different forms / behave in different ways depending on the context in which they are used.
It allows one interface (function, object, or operator) to behave differently depending on the context.

| Type                          | Also Called          | Achieved Using                                 | Binding       |
| ----------------------------- | -------------------- | ------------------------------------------     | ------------- |
| **Compile-time Polymorphism** | Static Polymorphism  | Function ,Operator and Constructor overloading | Early Binding |
| **Run-time Polymorphism**     | Dynamic Polymorphism | Virtual Functions, Function Overriding         | Late Binding  |

Compile-time → Decided before the program runs

Run-time → Decided while the program runs (needs virtual)


*/
//COMPILE TIME POLYMORPHISM
//1)Function overloading: Same function name,same class, different parameter lists.
#include <iostream>
using namespace std;

class Math {
public:
    int add(int a, int b) {
        return a + b;
    }

    double add(double a, double b) {
        return a + b;
    }

    int add(int a, int b, int c) {
        return a + b + c;
    }
};

int main() {
    Math m;
    cout << m.add(2, 3) << endl;       // add(int, int)
    cout << m.add(2.5, 3.5) << endl;   // add(double, double)
    cout << m.add(1, 2, 3) << endl;    // add(int, int, int)
}

/* 
2)Operator overloading
Operator overloading means giving new meaning to existing C++ operators (like +, -, ==, etc.) for user-defined types (like classes).

You can make operators work on your own objects — not just built-in types.

Compiler doesn’t know what ‘+’ means for your class.
So you must define (overload) it yourself.
SYNTAX
returnType operator<symbol>(arguments)
Complex operator+(Complex const &obj);
 
Allowed to overload
+ - * / % == != < > <= >= [] () -> ++ -- =

Cannot overload
. :: ?: sizeof typeid

*/
//Complex Numbers
#include <iostream>
using namespace std;

class Complex {
    int real, imag;

public:
    Complex(int r = 0, int i = 0) {
        real = r;
        imag = i;
    }

    //  Overload the '+' operator
    Complex operator + (Complex const &obj) {
        Complex result;
        result.real = real + obj.real;
        result.imag = imag + obj.imag;
        return result;
    }

    void display() {
        cout << real << " + " << imag << "i" << endl;
    }
};

int main() {
    Complex c1(3, 2);
    Complex c2(1, 7);

    Complex c3 = c1 + c2;   // compiler calls c1.operator+(c2)
    c3.display();            // 4 + 9i
}

//compare two objects.
#include <iostream>
using namespace std;

class Student {
    int id;
public:
    Student(int i) : id(i) {}

    bool operator == (Student const &s) {
        return id == s.id;
    }
};

int main() {
    Student s1(101), s2(101), s3(102);

    if (s1 == s2)
        cout << "Same Student" << endl;
    else
        cout << "Different Students" << endl;

    if (s1 == s3)
        cout << "Same Student" << endl;
    else
        cout << "Different Students" << endl;
}

//3)Constructor overloading (refer constructors.cpp)
//RUN TIME POLYMORPHISM
/* 
1)Function overriding:-parent & child both contain the same function with different implementation.
Parent class function is said to be overriden.

Function overriding means redefining a base class function in the derived class with the same name, return type, and parameters.

Child class replaces (or overrides) the behavior of its parent class function.


 Base and derived class must have **same function name**          
 **Same number and type of parameters**                           
 **Same return type** (or covariant return allowed)               
 There must be **inheritance**                                   
 Use `virtual` keyword in base class for **runtime polymorphism** 

*/
//wITHOUT VIRTUAL
#include <iostream>
using namespace std;

class Animal {
public:
    void sound() {
        cout << "Animal makes sound" << endl;
    }
};

class Dog : public Animal {
public:
    void sound() {   // same name, same parameters
        cout << "Dog barks" << endl;
    }
};

int main() {
    Dog d;
    d.sound();   // Output: Dog barks 
}
/*
2)Virtual Functions:member function in a base class that you expect to override in derived classes.






*/