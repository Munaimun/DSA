#include <bits/stdc++.h>
using namespace std;

// Class representing a product with a name and price
class Product
{
public:
    string name;
    double price;

    // Constructor to initialize product details
    Product(string name, double price) : name(name), price(price) {}
};

// Class representing a shopping cart which holds multiple products
class ShoppingCart
{
public:
    // Vector to store pointers to products added to the cart
    vector<Product *> products;

    // Method to add a product pointer to the cart
    void addProduct(Product *p)
    {
        products.push_back(p);
    }

    // Getter method to retrieve the list of products
    const vector<Product *> &getProduct()
    {
        return products;
    }

    // Calculate the total price of all products in the cart
    double calculateTotal()
    {
        double total = 0;
        for (auto p : products)
            total += p->price;

        return total;
    }
};

// Class responsible for printing the invoice of the shopping cart
class CartPrinter
{
private:
    ShoppingCart *cart; // Pointer to the shopping cart to print from

public:
    // Constructor accepting the shopping cart to print
    CartPrinter(ShoppingCart *cart)
    {
        this->cart = cart;
    }

    // Prints the invoice listing each product and the total cost
    void printInvoice()
    {
        cout << "Invoice:\n";
        for (auto p : cart->getProduct())
            cout << p->name << " - $" << p->price << endl;

        cout << "Total: $" << cart->calculateTotal() << endl;
    }
};

// Abstract base class representing persistence (storage) of the cart
class Persistence
{
private:
    ShoppingCart *cart;

public:
    // Pure virtual function to save the shopping cart - to be implemented by subclasses
    virtual void save(ShoppingCart *cart) = 0;
};

// Concrete class implementing persistence via SQL database
class SQLPersistance : public Persistence
{
public:
    void save(ShoppingCart *cart) override
    {
        cout << "Saved to SQL DB\n";
    }
};

// Concrete class implementing persistence via MongoDB
class MongoPersistance : public Persistence
{
public:
    void save(ShoppingCart *cart) override
    {
        cout << "Saved to MongoDB\n";
    }
};

int main()
{
    // Create a shopping cart instance
    ShoppingCart *cart = new ShoppingCart();

    // Add products to the cart
    cart->addProduct(new Product("MacBook", 120000));
    cart->addProduct(new Product("Samsung fold 7", 140000));

    // Create a CartPrinter and print the invoice for the cart
    CartPrinter *printer = new CartPrinter(cart);
    printer->printInvoice();

    SQLPersistance sqlSaver;
    MongoPersistance mongoSaver;
    // Save the cart to different databases
    sqlSaver.save(cart);
    mongoSaver.save(cart);

    // Delete each product pointer to avoid memory leaks
    for (auto p : cart->getProduct())
    {
        delete p;
    }
    delete cart;
    delete printer;

    return 0;
}
