#include <bits/stdc++.h>
using namespace std;

class Payment
{
private:
    int amount;
    string transactionId;

public:
    // Setter methods
    void setAmount(int amt)
    {
        amount = amt;
    }

    void setTransactionId(string tid)
    {
        transactionId = tid;
    }

    // Getter methods
    int getAmount()
    {
        return amount;
    }

    string getTransactionId()
    {
        return transactionId;
    }

    void showInfo()
    {
        cout << "Amount: " << amount << " TransactionId: " << transactionId << endl;
    }

    void processPayment()
    {
        cout << "Processing payment...\n";
    }
};

int main()
{
    Payment p;
    p.setAmount(1000);
    p.setTransactionId("TXN123456");

    p.showInfo();

    return 0;
}
