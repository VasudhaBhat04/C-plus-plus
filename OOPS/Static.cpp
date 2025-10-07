/*
Static keyword in c++:
-> Static Variables in a Function
-> Static Member Variable in a Class
-> Static Member Functions in a Class
-> Global Static Variable

*/
/*
1) Static Variables in a Function
Value persists between function calls.
Only initialized once.
Normal local variables reset every call.
static local variable remembers its value between calls.
*/

#include <iostream>
using namespace std;

void counter() {
    static int count = 0;  // static variable
    count++;
    cout << "Count: " << count << endl;
}

int main() {
    counter();  // Count: 1
    counter();  // Count: 2
    counter();  // Count: 3
}

/*
2)Static Member Variable in a Class
Shared by all objects of the class.
Exists even if no object is created.
*/

#include <iostream>
using namespace std;

class Student {
public:
    static int totalStudents;  // static member
    string name;

    Student(string n) {
        name = n;
        totalStudents++;
    }
};

int Student::totalStudents = 0; // Must define outside the class
//Accessed using class name: Student::totalStudents
int main() {
    Student s1("Alice");  //totalStudents is shared by s1 & s2
    Student s2("Bob");
 
    cout << "Total students: " << Student::totalStudents << endl;  // 2
}

/*
3)Static Member Functions in a Class
Can only access static members.
Can be called without an object.
*/

#include <iostream>
using namespace std;

class Student {
public:
    static int totalStudents;

    static void showTotal() {   // static function
        cout << "Total students: " << totalStudents << endl;
    }
};

int Student::totalStudents = 5;

int main() {
    Student::showTotal();  // Call without object
}

/*
4)Static Global Variables and Functions
If a global variable is declared static, it is visible only in that file (internal linkage).
Not accessible from other files.
Similarly, static function is file-scope only.
*/
// file1.cpp
static int x = 10;  // Only accessible inside file1.cpp
static void greet() {
    cout << "Hello!" << endl;
}
