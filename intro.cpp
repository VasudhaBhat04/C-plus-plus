//OOPS - Programming model that uses objects & classes to design applications & computer programs.
// For better organisation of code , reusability, build adaptable, scalable, and maintainable software systems.

/* Objects --> entities in real world
   Class --> Blueprint of these entites(group of objects)
   These onjects contain data(attribute/properties) & code(methods/functions)that operate on data.

*/
/* CLASS SYNTAX:
Class className{
Access_specifier
Data members
Member functions
}

OBJECT CREATION:
 class_name object_name;
  object_name.attribute = " "

Objects and classes are the building blocks for object-oriented programming that help implement real-world entities in programming languages. The five main pillars of OOPs in C++ are:

Class and object
Inheritance
Polymorphism
Abstraction
Encapsulation
*/
#include<iostream>
#include<string>
using namespace std;

class Student{
public:
    int age;
    string name;

    void get_gpa(double gpa){
         if (gpa > 7.8) {
        cout << "Good";
    } else if (gpa < 7.8) {
        cout << "Bad";
    } else {
        cout << "Average"; 
    }

    }
};
int main(){
    Student s1;
    s1.age = 20;
    s1.name = "Ken";
    s1.get_gpa(8.2);
    cout<<s1.age;
    cout<<s1.name;
    
    return 0;
}