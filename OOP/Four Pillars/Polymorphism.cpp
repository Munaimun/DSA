#include <bits/stdc++.h>
using namespace std;

//
class Student
{
public:
    string name;

    // Constructor Overloading (Compile-time Polymorphism):
    // 1. Non-parameterized constructor (called when no argument is passed)
    Student()
    {
        cout << "Non-parameterized constructor called\n";
    };

    // 2. Parameterized constructor (called when one argument is passed)
    Student(string name)
    {
        cout << "Parameterized constructor called\n";
        this->name = name; // optional assignment
    };
};

// Another class to demonstrate function overloading
class Print
{
public:
    // Function Overloading (Compile-time Polymorphism):
    // 1. show() function to print an integer
    void show(int x)
    {
        cout << "Integer: " << x << endl;
    };

    // 2. show() function to print a character
    void show(char x)
    {
        cout << "Character: " << x << endl;
    };
};

int main()
{
    // ========================
    // Constructor Overloading
    // ========================

    // Calls the non-parameterized constructor (no argument passed)
    Student s1;

    // Calls the parameterized constructor (string argument passed)
    Student s2("Fahad");

    // ========================
    // Function Overloading
    // ========================
    Print p;

    // Calls show(int x) - since 5 is an integer
    p.show(5);

    // Calls show(char x) - since 'a' is a character
    p.show('a');

    return 0;
}
