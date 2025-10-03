/*
Inheritance is an OOP concept where a class (called derived/child class) can inherit properties and methods from another class (called base/parent class).

Purpose: Code reusability and hierarchical relationships.

Types of Inheritance in C++
Single Inheritance – One child inherits from one parent.
Multiple Inheritance – One child inherits from more than one parent.
Multilevel Inheritance – Chain of inheritance (grandparent → parent → child).
Hierarchical Inheritance – One parent, multiple children.
Hybrid Inheritance – Combination of two or more types above.

Base class always called first
*/ 
//Single Inheritance
#include <iostream>
using namespace std;

class Person{
    public:
    string name;
    int age;
    Person(){
        cout<<"Hi i am the parent constructor";
    }
};
class Student:public Person{
    public:
    int usn;
    Student(){
       cout<<"Hi i am the child constructor";
    }

    void getInfo(){
        cout<<name<<" "<<age<<" "<<usn<<endl;
    }
};
int main(){
     Student s1;
     s1.name="Luna";
     s1.age=12;
     s1.usn=123456;
     s1.getInfo();
     return 0;

     //Person p1 --> constructor get called

}
//Multilevel Inheritance
#include <iostream>
using namespace std;

class Person{
    public:
    string name;
    int age;
    Person(){
        cout<<"Hi i am the parent constructor\n";
    }
    ~Person(){
       cout<<"Hi i am the parent destructor\n";
    }
};
class Student:public Person{
    public:
    int usn;
    Student(){
       cout<<"Hi i am the child constructor\n";
    }
    ~Student(){
       cout<<"Hi i am the child destructor\n";
    }
};
class GradStudent:public Student{
    public:
    string reasearchArea;
    GradStudent(){
       cout<<"Hi i am the grandchild constructor\n";
    }
    void getInfo(){
        cout<<name<<" "<<age<<" "<<usn<<" "<<reasearchArea<<endl;
    }
    ~GradStudent(){
       cout<<"Hi i am the grandchild destructor\n";
    }
    
};
int main(){
     GradStudent g1;
     g1.name="Laxmi";
     g1.age=13;
     g1.usn=121126;
     g1.reasearchArea="Covid vaccines";
     g1.getInfo();
     return 0;

}
//Multiple Inheritance //child inherits from 2 or more parent class
#include <iostream>
using namespace std;

class Student{
    public:
    string name;
    int rollno;
};
class Teacher{
     public:
     string subject;
     double salary;

};

class Training:public Student,public Teacher{
    public:
    void show(){
        cout<<"Name:"<<name<<endl;
        cout<<"Id:"<<rollno<<endl;
        cout<<"Subject:"<<subject<<endl;
        cout<<"Salary:"<<salary<<endl;
    }
};
int main(){
    Training t1;
    t1.name="Mikasa Ackerman";
    t1.rollno=14;
    t1.subject="Protecting Eren";
    t1.salary=15000;
    t1.show();

    Training t2;
    t2.name="Levi Ackerman";
    t2.rollno=14;
    t2.subject="Slaying titans";
    t2.salary=25000;
    t2.show();
}
//Hierarchial 2/more child inherit from same parent class
#include <iostream>
using namespace std;

class Parent {
public:
    void funcParent() { cout << "Function of Parent" << endl; }
};

class Child1 : public Parent {  
public:
    void funcChild1() { cout << "Function of Child1" << endl; }
};

class Child2 : public Parent {  
public:
    void funcChild2() { cout << "Function of Child2" << endl; }
};

int main() {
    Child1 c1;
    Child2 c2;
    c1.funcParent();
    c1.funcChild1();
    c2.funcParent();
    c2.funcChild2();
    return 0;
}

//Hybrid Inheritence Combination of multiple and multilevel inheritance
#include <iostream>
using namespace std;

// Base class
class Base1 {
public:
    void funcBase1() { cout << "Function of Base1" << endl; }
};

// Derived from Base1
class Derived1 : public Base1 {
public:
    void funcDerived1() { cout << "Function of Derived1" << endl; }
};

// Another base class
class Base2 {
public:
    void funcBase2() { cout << "Function of Base2" << endl; }
};

// Hybrid child
class Hybrid : public Derived1, public Base2 {
public:
    void funcHybrid() { cout << "Function of Hybrid" << endl; }
};

int main() {
    Hybrid h;
    h.funcBase1();    // from Base1 via Derived1
    h.funcDerived1(); // from Derived1
    h.funcBase2();    // from Base2
    h.funcHybrid();   // own function
    return 0;
}






















/*
| Mode of Inheritance | Syntax Example                        | Base Class Member Accessibility in Derived Class                       | Notes                                                                                                   |
| ------------------- | ------------------------------------- | ---------------------------------------------------------------------- | ------------------------------------------------------------------------------------------------------- |
| **Public**          | `class Derived : public Base { };`    | Public → Public<br>Protected → Protected<br>Private → Not inherited    | Most common. “Is-a” relationship.                                                                       |
| **Protected**       | `class Derived : protected Base { };` | Public → Protected<br>Protected → Protected<br>Private → Not inherited | Members of base become protected in derived. Useful for controlled access.                              |
| **Private**         | `class Derived : private Base { };`   | Public → Private<br>Protected → Private<br>Private → Not inherited     | Members of base become private in derived. Often used for “implemented-in-terms-of” rather than “is-a”. |


*/
#include <iostream>
using namespace std;

class Base {
public:      //Accessible anywhere
    int a = 1;
protected:   //Accessible only in derived 
    int b = 2;
private:   //Not inherited
    int c = 3;
};

// Public inheritance
class DerivedPublic : public Base {
public:
    void show() {
        cout << "Public Inheritance:" << endl;
        cout << "a = " << a << endl;     // accessible
        cout << "b = " << b << endl;   // accessible
        // cout << "c = " << c << endl; // Not accessible
    }
};

// Protected inheritance
class DerivedProtected : protected Base {
public:
    void show() {
        cout << "Protected Inheritance:" << endl;
        cout << "a = " << a << endl;     // becomes protected can modify inside derived
        cout << "b = " << b << endl;   // accessible
        // cout << "c = " << c << endl; // Not accessible
    }
};

// Private inheritance
class DerivedPrivate : private Base {
public:
    void show() {
        cout << "Private Inheritance:" << endl;
        cout << "a = " << a << endl;     // becomes private can't modify
        cout << "b = " << b << endl;   // becomes private
        // cout << "c = " << c << endl; // Not accessible
    }
};

int main() {
    DerivedPublic dp;
    dp.show();
    dp.a = 10;  // public inheritance: a is public in derived u can change the value

    DerivedProtected dpr;
    dpr.show();
    // dpr.a = 10; // protected inheritance: a becomes protected unable to modify

    DerivedPrivate dpt;
    dpt.show();
    // dpt.a = 10; // private inheritance: a becomes private

    return 0;
}
