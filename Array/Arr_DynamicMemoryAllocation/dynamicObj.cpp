#include <bits/stdc++.h>
using namespace std;

// Define a class named 'Student'
class Student
{
public:
    int roll;

    // Constructor to initialize the roll number
    Student(int roll)
    {
        this->roll = roll; // 'this' pointer refers to the current object
    }

    void print()
    {
        cout << "Roll: " << roll << endl;
    }
};

void changeRoll(Student *obj)
{
    obj->roll = 100;
};

int main()
{
    // Create a Student object dynamically using 'new' and store its address in a pointer
    Student *obj = new Student(13); // 'obj' points to a Student with roll number 13

    // Access and print the roll number using the pointer
    cout << obj->roll << endl;

    changeRoll(obj); // now it will change the roll
    obj->print();

    return 0;
}
