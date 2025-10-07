/*
Templates in C++:-
Code that works with any data type (int, float, string, etc.) without rewriting it.
Templates = “Type parameters” for functions or classes.

SYNTAX:

template <typename T> or template <class T>
T functionName(T param1, T param2) {
    // code
}

*/

#include <iostream>
using namespace std;

template <typename T>
T add(T a, T b) {
    return a + b;
}

int main() {
    cout << add(10, 20) << endl;       // int
    cout << add(2.5, 3.8) << endl;     // double
    cout << add(String("Hi "), String("there!")) << endl; // string
    return 0;
}

//Class Templates

#include <iostream>
using namespace std;

template <class T>
class Box {
    T value;
public:
    Box(T v) : value(v) {}
    void show() {
        cout << "Value: " << value << endl;
    }
};

int main() {
    Box<int> b1(100);
    Box<string> b2("Hello Template!");

    b1.show();
    b2.show();
    return 0;
}
