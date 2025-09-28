#include <bits/stdc++.h>
using namespace std;

class Person
{
public:
    string name;
    int age;

    // Person(string name, int age)
    // {
    //     this->name = name;
    //     this->age = age;
    // }

    Person()
    {
    }
};

// another class with inheritance which inherit the person class
class Student : public Person
{
public:
    int id;

    void getInfo()
    {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "id: " << id << endl;
    }
};

int main()
{
    Student s1;

    s1.name = "Fahad";
    s1.age = 25;
    s1.id = 19148;

    s1.getInfo();

    return 0;
}