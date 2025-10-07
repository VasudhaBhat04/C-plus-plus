/*
Destructor (default by constructor for static ones)
A destructor is a special member function of a class.
It is automatically called when an object goes out of scope or is deleted.
Its main purpose is to release resources (memory, file handles, sockets, etc.) that the object used.
Same name as class name
Only 1 destructor per class ,preceded by a ~ (tilde)..
Destructor is called automatically in reverse order of object creation.

//SYNTAX
class ClassName {
public:
    ~ClassName() {
        // code to clean up resources
    }
};

*/
#include <iostream>
using namespace std;

class Student {
private:
    string name;

public:
    Student(string n) {
        name = n;
        cout << "Constructor called for " << name << endl;
    }

    ~Student() {
        cout << "Destructor called for " << name << endl;
    }
};

int main() {
    Student s1("SpongeBob");
    Student s2("Patrick");

    cout << "Inside main function" << endl;

    return 0;
}
/*
Constructor called for SpongeBob
Constructor called for Patrick
Inside main function
Destructor called for Patrick
Destructor called for SpongeBob
*/

/* 

Destructor for dynamic memory

#include <iostream>
using namespace std;

class Array {
private:
    int *data;
    int size;

public:
    Array(int s) {
        size = s;
        data = new int[size];  // allocate memory
        cout << "Array of size " << size << " created." << endl;
    }

    ~Array() {
        delete[] data;  // free memory
        cout << "Array destroyed and memory freed." << endl;
    }
};

int main() {
    Array a1(5);  // constructor called
    Array a2(10); // constructor called

    return 0;  // destructor called automatically for a2 and a1
}

*/
/*

| Feature   | Constructor                      | Destructor                          |
| --------- | -------------------------------- | ----------------------------------- |
| Name      | Same as class                    | ~ClassName                          |
| Purpose   | Initialize objects               | Clean up objects/resources          |
| Arguments | Can take arguments               | No arguments                        |
| Call      | Automatically called on creation | Automatically called on destruction |
| Multiple  | Can overload                     | Only one per class                  |


*/