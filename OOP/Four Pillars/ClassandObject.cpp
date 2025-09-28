#include <bits/stdc++.h>
using namespace std;

class Student
{
public:
    string name;
    double cgpa;

    // constructor
    Student(string name, double cgpa)
    {
        this->name = name;
        this->cgpa = cgpa;
    }

    void getInfo()
    {
        cout << "Name: " << name << endl;
        cout << "cgpa: " << cgpa << endl;
    }
};

int main()
{
    Student s1("Fahad", 3.45);
    s1.getInfo();

    return 0;
}