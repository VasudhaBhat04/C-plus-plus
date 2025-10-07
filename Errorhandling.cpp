/*
Error handling is how a program responds to runtime errors instead of crashing.
In C++, we use exceptions to handle errors.
| Keyword | Purpose                                     |
| ------- | ------------------------------------------- |
| `try`   | Block of code that might throw an exception |
| `throw` | Actually throws an exception                |
| `catch` | Block that handles the exception            |

SYNTAX:
try {
    // code that may throw an exception
    if(someError) {
        throw errorValue;  // throw an exception
    }
}
catch(Type e) {
    // code to handle the exception
    cout << "Error: " << e << endl;
}

throw can throw any type (int, string, object, etc.)

catch type must match throw type

Multiple catch blocks can be used to handle different types of exceptions
*/
#include <iostream>
using namespace std;

int main() {
    int x = 0;
    try {
        cout << "Enter a number: ";
        cin >> x;
        if (x == 0) {
            throw "Division by zero error";  // throw exception
        }
    }
    catch (const char* e) {
        cout << "Caught an exception: " << e << endl;
    }

    cout << "Program continues..." << endl;
    return 0;
}
/*
Reasons We Need Error Handling:-
A.Prevent Program Crashes

Example: dividing by zero, accessing invalid memory, opening a missing file.
Without handling, the program stops abruptly.

B.Graceful Recovery

Allows the program to recover or continue running instead of crashing.

C.Better User Experience

Instead of seeing a crash or garbage output, the user sees a clear error message.

Programs can fail at runtime; we must anticipate this.
Error handling makes programs robust, reliable, and user-friendly.
It helps in resource cleanup, especially in C++.
Without error handling, your program is fragile and prone to crashes.

*/