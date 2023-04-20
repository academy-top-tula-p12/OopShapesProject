#include <iostream>
#include "MultiClass.h"
using namespace std;

class Shape
{
protected:
    int x;
    int y;
public:
    Shape(int x, int y) : x{ x }, y{ y } {}
    Shape() : Shape(0, 0) {}

    virtual string Name() = 0;
    //virtual double Square() = 0;
    //virtual double Perimetr() = 0;
};

class Shape2d : public Shape
{
public:
    Shape2d(int x, int y) : Shape(x, y) {}
    Shape2d() : Shape(0, 0) {}
    virtual double Square() = 0;
    virtual double Perimetr() = 0;
};

class Shape3d : public Shape
{
protected:
    int z;
public:
    Shape3d(int x, int y, int z) : Shape(x, y), z{ z } {}
    Shape3d() : Shape3d(0, 0, 0) {}
    virtual double SquareArea() = 0;
    virtual double Volume() = 0;
};

class Cube : public Shape3d
{
    double length;
public:
    Cube(int x, int y, int z, double length)
        : Shape3d(x, y, z), length{ length } {}
    Cube(double length) : Cube(0, 0, 0, length) {}
    Cube() : Cube(0, 0, 0, 0) {}

    string Name() override
    {
        return "Cube";
    }
    double SquareArea() override
    {
        return length * length * 6;
    }
    double Volume() override
    {
        return length * length * length;
    }
};

class Rectangle : public Shape2d
{
    double width;
    double height;
public:
    Rectangle(int x, int y, double width, double height)
        : Shape2d(x, y), width{ width }, height{ height } {}

    Rectangle(double width, double height) 
        : Rectangle(0, 0, width, height) {};

    Rectangle() : Rectangle(0, 0, 0, 0) {}

    string Name() override
    {
        return "Rectangle";
    }

    double Square() override
    {
        return width * height;
    }
    double Perimetr() override
    {
        return 2 * (width + height);
    }
};

class Circle : public Shape2d
{
    const double PI = 3.1416;
    double radius;
public:
    Circle(int x, int y, double radius)
        : Shape2d(x, y), radius{ radius } {}
    Circle(double radius) : Circle(0, 0, radius) {}
    Circle() : Circle(0, 0, 0) {}

    string Name() override
    {
        return "Circle";
    }
    double Square() override
    {
        return PI * radius * radius;
    }
    double Perimetr() override
    {
        return 2 * PI * radius;
    }
};


void MultiClassExample();
int main()
{
    Rectangle* rec = new Rectangle(23, 45);
    cout << rec->Perimetr();


    Shape* shape;
    Rectangle* rectangle = new Rectangle(5, 6, 12, 16);
    Circle* circle = new Circle(15.0);

    Shape* shapePtr = circle;
    //cout << ((Circle*)shapePtr)->Square() << "\n";
    //cout << circle->Square() << "\n";


    Shape** shapes = new Shape*[4];
    shapes[0] = new Rectangle(2, 6);
    shapes[1] = new Rectangle(12, 34);
    shapes[2] = new Circle(15);
    shapes[3] = new Cube(25);

    for (int i = 0; i < 4; i++)
        cout << shapes[i]->Name() << "\n";

    for (int i = 0; i < 4; i++)
        delete shapes[i];
    delete[] shapes;
}

void MultiClassExample()
{
    Mfu* mfu = new Mfu();
    mfu->Print();
    mfu->Scan();
    mfu->Printer::PrintName();
    mfu->Scanner::PrintName();
}