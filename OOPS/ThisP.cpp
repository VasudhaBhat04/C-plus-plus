/*
This pointer --> a special pointer in C++ that points to the current object (the object that is calling the function).
this -> prop is same as *(this).prop

Why do we need this pointer?
To refer to the current object’s members (especially when local variable names are same as data members).
To return the current object from a method (method chaining).
To pass the current object as an argument.

*/
//Differeniate between insance variable & class variable
#include <iostream>
using namespace std;

class Student {
private:
    string name;
    int age;

public:
    // Constructor using same parameter names as members
    Student(string name, int age) {
        // 'this->' helps differentiate between member variable & local parameter
        this->name = name;
        this->age = age;
    }

    void display() {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};

int main() {
    Student s1("SpongeBob", 20);
    s1.display();
    return 0;
}


//Returning the current object (method chaining)
#include <iostream>
using namespace std;

class Box {
private:
    int length;

public:
    Box(int l=0) 
    { length = l; }

    // return *this allows method chaining
    Box& setLength(int l) {
        this->length = l;
        return *this; // return current object reference
    }

    void show() {
        cout << "Length: " << length << endl;
    }
};

int main() {
    Box b;
    b.setLength(10).setLength(20).setLength(30); // method chaining
    b.show();
    return 0;
}
//Output Length:30


//Passing current object
#include <iostream>
using namespace std;

class Test {
public:
    void compare(Test &t) {
        if(this == &t) // check if same object
            cout << "Both are same object" << endl;
        else
            cout << "Different objects" << endl;
    }
};

int main() {
    Test obj1, obj2;
    obj1.compare(obj1); // same object
    obj1.compare(obj2); // different object
    return 0;
}
