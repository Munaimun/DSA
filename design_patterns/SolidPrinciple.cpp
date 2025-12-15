#include <bits/stdc++.h>
using namespace std;

// ==== Product Class ====
// Represents a product with a name and price
class Product
{
public:
    string name;
    double price;

    // Constructor to initialize product attributes
    Product(string name, double price) : name(name), price(price) {}
};

// ==== ShoppingCart (SRP) ====
// Single Responsibility Principle:
// This class only manages products and calculates totals.
class ShoppingCart
{
private:
    vector<Product> items; // Stores list of products

public:
    // Add a product to the cart by copying it
    void addProduct(const Product &p)
    {
        items.push_back(p);
    }

    // Calculate total price of all products in cart
    double getTotalPrice() const
    {
        double total = 0;
        for (const auto &p : items)
            total += p.price;
        return total;
    }

    // Getter for products - returns const reference to prevent modification
    const vector<Product> &getProducts() const
    {
        return items;
    }
};

// ==== IPrinter Interface (ISP) ====
// Interface Segregation Principle:
// Only defines a contract for printing invoices.
class IPrinter
{
public:
    // Pure virtual method to print an invoice given a shopping cart
    virtual void printInvoice(const ShoppingCart &cart) = 0;

    // Virtual destructor to ensure proper cleanup of derived classes
    virtual ~IPrinter() = default;
};

// ==== ConsolePrinter (OCP, LSP) ====
// Open-Closed Principle: Extends IPrinter without modifying it
// Liskov Substitution Principle: Can be used wherever IPrinter is expected
class ConsolePrinter : public IPrinter
{
public:
    // Override printInvoice to output to console
    void printInvoice(const ShoppingCart &cart) override
    {
        cout << "Invoice:\n";
        for (const auto &p : cart.getProducts())
            cout << p.name << " - $" << p.price << "\n";
        cout << "Total: $" << cart.getTotalPrice() << "\n";
    }
};

// ==== IDatabase Interface (ISP) ====
// Interface Segregation Principle:
// Only defines a contract for saving carts.
class IDatabase
{
public:
    // Pure virtual method to save the cart
    virtual void saveCart(const ShoppingCart &cart) = 0;

    virtual ~IDatabase() = default;
};

// ==== MySQLDatabase (OCP, LSP) ====
// Open-Closed Principle: New database type implemented without changing existing code
// Liskov Substitution Principle: Fulfills IDatabase interface contract
class MySQLDatabase : public IDatabase
{
public:
    // Save the cart by printing to simulate database save
    void saveCart(const ShoppingCart &cart) override
    {
        cout << "Saving cart to MySQL Database...\n";
        for (const auto &p : cart.getProducts())
            cout << "Saved: " << p.name << " - $" << p.price << "\n";
    }
};

// ==== InvoiceManager (DIP) ====
// Dependency Inversion Principle:
// Depends on abstractions (IPrinter, IDatabase) rather than concrete implementations.
// High-level module orchestrating printing and saving.
class InvoiceManager
{
private:
    IPrinter &printer;
    IDatabase &database;

public:
    // Constructor accepts references to abstractions (dependency injection)
    InvoiceManager(IPrinter &p, IDatabase &db) : printer(p), database(db) {}

    // Handles checkout by printing invoice and saving the cart
    void checkout(ShoppingCart &cart)
    {
        printer.printInvoice(cart);
        database.saveCart(cart);
    }
};

// ==== Main Function ====
// Demonstrates the usage of the above classes following SOLID principles.
int main()
{
    // Create a shopping cart and add products
    ShoppingCart cart;
    cart.addProduct(Product("Laptop", 1200.0));
    cart.addProduct(Product("Mouse", 25.0));

    // Create concrete implementations of printer and database
    ConsolePrinter printer;
    MySQLDatabase db;

    // Inject dependencies into InvoiceManager
    InvoiceManager manager(printer, db);

    // Perform checkout which prints invoice and saves cart
    manager.checkout(cart);

    return 0;
}