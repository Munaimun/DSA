#include <bits/stdc++.h>
using namespace std;

class Teacher
{

    // properties
private: //<- making the properties and methods private
    double salary;

public: // <- making all the properties and methods accessible
    // properties
    string name;
    string dept;
    string subject;

    // CONSTRUCTOR

    // non-parameterized
    Teacher() // bcoz of this, all dept value will be Science by default
    {
        dept = "Science";
    }

    // parameterized
    Teacher(string name, string dept, string subject, double salary)
    {
        // this pointer refers to the objects property
        this->name = name;
        this->dept = dept;
        this->subject = subject;
        this->salary = salary;
    }

    // methods
    void changeDept(string newDept)
    {
        dept = newDept;
    }

    // method to get the private property
    // setter
    void setSalary(double s)
    {
        salary = s;
    }
    // getter
    double getSalary()
    {
        return salary;
    }

    ~Teacher()
    {
        cout << "I'm a destructor and I have delete everything\n.";
    }

    void getInfo()
    {
        cout << "Name: " << name << endl;
        cout << "Dept: " << dept << endl;
    }
};

int main()
{
    // non-parameterized rule for creating object
    // Teacher t1;
    // t1.name = "Fahad";
    // t1.subject = "DSA";
    // t1.setSalary(250000);

    // parameterized rule for creating object
    Teacher t1("fahad", "CSE", "DSA", 250000);

    Teacher t2(t1); // copy constructor
    t2.getInfo();
    return 0;
}