#include <bits/stdc++.h>
using namespace std;

// Abstract class = interface
class Payment
{
public:
    // pure virtual functions (interface methods)
    virtual void Pay() = 0;
    virtual void ShowInfo() = 0;
};

// Implementing class
class CreditCardPayment : public Payment
{
public:
    void Pay() override
    {
        cout << "Payment by credit card\n";
    }

    void ShowInfo() override
    {
        cout << "Credit card info\n";
    }
};

class BkashPayment : public Payment
{
public:
    void Pay() override
    {
        cout << "Payment done by bkash\n";
    }

    void ShowInfo() override
    {
        cout << "Bkash account info\n";
    }
};

int main()
{

    CreditCardPayment c;
    c.Pay();
    c.ShowInfo();

    // polymorphism:
    Payment *p = new CreditCardPayment();
    p->Pay();
    p->ShowInfo();
    delete p;

    BkashPayment b;
    b.Pay();
    b.ShowInfo();

    return 0;
}
