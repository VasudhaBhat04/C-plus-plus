/*
Friend Function:

A friend function is a function not a member of a class, but it has access to the class’s private and protected members.
Declared inside the class using the friend keyword.
Useful when you want a function to work with multiple classes or access private data without being a member function.
Called like a normal function.
Friendhsip is not inherited,  is not reciprocal.
Can be invoked without the help of any object.
Can be declared inside public/private section of the class.

SYNTAX:
class ClassName {
private:
    int data;
public:
    ClassName(int d) : data(d) {}
    friend void showData(ClassName &obj);  // friend function declaration
};

// Definition outside class
void showData(ClassName &obj) {
    std::cout << "Data: " << obj.data << std::endl;  // can access private
}

*/

#include <iostream>
using namespace std;

class Box {
private:
    int length;
public:
    Box(int l) : length(l) {}

    // Friend function declaration
    friend void printLength(Box &b);
};

// Friend function definition
void printLength(Box &b) {
    cout << "Length of Box: " << b.length << endl;  // can access private member
}

int main() {
    Box b1(10);
    printLength(b1);  // call like normal function
}
