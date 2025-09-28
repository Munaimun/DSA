#include <bits/stdc++.h>
using namespace std;

class Notify
{
public:
    virtual void Send() = 0;
    virtual void Log() = 0;
    virtual void Save() = 0;
    virtual ~Notify() = default; // Virtual destructor
};

class EmailNotify : public Notify
{
private:
    string email;

public:
    void SetEmail(string email)
    {
        this->email = email;
    }

    void Send() override
    {
        cout << "Sending email to: " << email << endl;
    }

    void Log() override
    {
        cout << "Logging email to " << email << endl;
    }

    void Save() override
    {
        cout << "Email saved in history\n";
    }
};

class SMSNotify : public Notify
{
private:
    string number;

public:
    void SetNum(string num)
    {
        this->number = num;
    }

    void Send() override
    {
        cout << "Sending SMS to: " << number << endl;
    }

    void Log() override
    {
        cout << "Logging SMS to " << number << endl;
    }

    void Save() override
    {
        cout << "SMS saved in history\n";
    }
};

int main()
{
    // Create EmailNotify and SMSNotify instances
    EmailNotify *e = new EmailNotify();
    e->SetEmail("fahad@gmail.com");

    SMSNotify *s = new SMSNotify();
    s->SetNum("017XXXXXXXX");

    // Store pointers in a list of base class type
    vector<Notify *> notifiers;
    notifiers.push_back(e);
    notifiers.push_back(s);

    // Loop through and call all methods polymorphically
    for (Notify *n : notifiers)
    {
        n->Send();
        n->Log();
        n->Save();
        cout << "-------------------\n";
    }

    // Clean up
    for (Notify *n : notifiers)
        delete n;

    return 0;
}
