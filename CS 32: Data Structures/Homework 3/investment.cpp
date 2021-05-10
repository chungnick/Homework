//
//  main.cpp
//  Homework 3
//
//  Created by Nick Chung on 2/7/21.
//  ***

#include <iostream>
#include <string>

using namespace std;

class Investment {
public:
    Investment(string name, int price) : m_name(name), m_price(price) {};
    virtual ~Investment() {};
    virtual bool fungible() const {return false;}
    string name() const {return m_name;}
    int purchasePrice() const {return m_price;}
    virtual string description() const {
        return m_type;
    }
    virtual void x() = 0;
private:
    string m_name;
    int m_price;
    string m_type;
};

class House : public Investment {
public:
    House(string address, int price) : Investment(address, price) {};
    ~House() {
        cout << "Destroying the " << description() << " " << name() << endl;
    }
    virtual string description() const {
        return "house";
    }
    virtual void x() {}
};

class Stock : public Investment {
public:
    Stock(string name, int price, string stockName) : Investment(name, price), m_stockName(stockName) {}
    ~Stock() {
        cout << "Destroying " << name() << ", a stock holding" << endl;
    }
    virtual string description() const {
            string x = "stock trading as ";
            x += m_stockName;
            return x;
    }
    virtual bool fungible() const {
        return true;
    }
    virtual void x() {}
private:
    string m_stockName;
};

class Painting : public Investment {
public:
    Painting(string name, int price) : Investment(name, price) {};
    ~Painting() {
        cout << "Destroying " << name() << ", a painting" << endl;
    }
    virtual string description() const {
        return "painting";
    }
    virtual void x() {}
};

void display(const Investment* inv) {
    cout << inv->name();
    if (inv->fungible())
        cout << " (fungible)";
    cout << ": " << inv->description() << " bought for $" << inv->purchasePrice() << endl;
}

int main() {
    Investment* portfolio[4];
    portfolio[0] = new Painting("Salvator Mundi", 450300000);
      // Stock holdings have a name, value, and ticker symbol
    portfolio[1] = new Stock("Lyft", 50000, "LYFT");
    portfolio[2] = new Stock("GameStop", 10000, "GME");
    portfolio[3] = new House("4 Privet Drive", 660000);

    for (int k = 0; k < 4; k++)
        display(portfolio[k]);

      // Clean up the investments before exiting
    cout << "Cleaning up" << endl;
    for (int k = 0; k < 4; k++)
        delete portfolio[k];
}

//Salvator Mundi: painting bought for $450300000
//Lyft (fungible): stock trading as LYFT bought for $50000
//GameStop (fungible): stock trading as GME bought for $10000
//4 Privet Drive: house bought for $660000
//Cleaning up
//Destroying Salvator Mundi, a painting
//Destroying Lyft, a stock holding
//Destroying GameStop, a stock holding
//Destroying the house 4 Privet Drive
