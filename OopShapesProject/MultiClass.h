#include <iostream>
using namespace std;

class Gadget
{
public:
    string name;
};

class Printer : public Gadget
{
public:
    Printer()
    {
        name = "Printer";
    }
    void Print()
    {
        cout << "Printer work\n";
    }
    void PrintName()
    {
        cout << name << "\n";
    }
};

class Scanner : public Gadget
{
public:
    Scanner()
    {
        name = "Scanner";
    }
    void Scan()
    {
        cout << "Scanner work\n";
    }
    void PrintName()
    {
        cout << name << "\n";
    }
};

class Mfu : public Printer, public Scanner
{
public:

};


