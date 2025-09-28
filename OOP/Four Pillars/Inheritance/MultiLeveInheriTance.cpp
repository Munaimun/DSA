#include <bits/stdc++.h>
using namespace std;

class Person
{
public:
    string name;
    int age;
};

// first level of the inheritance
class RegularStudent : public Person
{
public:
    int id;
};

// second level of the inheritance
class GradStudent : public RegularStudent
{
public:
    string subject;
};

int main()
{

    return 0;
}