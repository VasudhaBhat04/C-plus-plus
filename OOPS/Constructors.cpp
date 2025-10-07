
/*Constructor-->Special method invoked automatically at the time of onject creation.
Used for intialization(defaultly initiated by the computer)
.Same name as class
.Doesn't have a return type
.Only called once(automatically)at the time of object creation.
.Memory allocation happens when constructor is called.
Can be overloaded (you can have multiple constructors).
Types 
|--->Non-parameterized
|--->Parameterized
|--->Copy constructor
     ClassName(const ClassName &oldObject) {
    // copy code here
}

*/
#include <iostream>
using namespace std;

class Student {
private:
    string name;
    int age;

public:
    // 1️ Default Constructor
    Student() {
        name = "Unknown";
        age = 0;
        cout << "Default Constructor called!" << endl;
    }

    // 2️ Parameterized Constructor
    Student(string n, int a) {   //Constructor overloading --> 2 constructor with same name given different parameter types & their no.s
        name = n;   
        age = a;
        cout << "Parameterized Constructor called!" << endl;
    }

    // 3️ Copy Constructor Optional to write this block
    Student(const Student &s) {
        name = s.name;
        age = s.age;
        cout << "Copy Constructor called!" << endl;
    }

    void display() {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};

int main() {
    // Object using Default Constructor
    Student s1;
    s1.display();

    // Object using Parameterized Constructor
    Student s2("SpongeBob", 20);
    s2.display();

    // Object using Copy Constructor
    Student s3(s2); // Copy s2 into s3 //Compiler will still copy the smae withput the above CC block
    s3.display();

    return 0;
}





