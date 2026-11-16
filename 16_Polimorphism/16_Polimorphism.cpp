#include <iostream>
using namespace std;
class Shape
{
private:
    string name;
    string type;
protected:
    string color; 
public:
    Shape() : name("no name"), type("unknown"), color("white") {}
    Shape(string n, string t, string c) : name(n), type(t), color(c) {}
    virtual void Show() const
    {
        cout << "Name : " << name << endl;
        cout << "Type : " << type << endl;
        cout << "Color : " << color << endl;
    }
    virtual double GetArea() const
    {
        return 0;
    }
};
class Rectangle : public Shape
{
    double width;
    double height;
public:
    Rectangle() : width(0), height(0), Shape("no name", "Rectangle", "white") {}
    Rectangle(string n, string c, double w, double h)
        : width(w), height(h), Shape(n, "Rectangle", c) {
    }
    double GetArea() const override
    {
        return width * height;
    }
    void Show() const override
    {
        cout << "Rectangle:" << endl;
        Shape::Show();
        cout << "Width : " << width << endl;
        cout << "Height : " << height << endl;
    }
};
class Circle : public Shape
{
    double radius;
public:
    Circle() : radius(0), Shape("no name", "Circle", "white") {}
    Circle(string n, string c, double r)
        : radius(r), Shape(n, "Circle", c) {
    }
    double GetArea() const override
    {
        return 3.14159 * radius * radius;
    }
    void Show() const override
    {
        cout << "Circle:" << endl;
        Shape::Show();
        cout << "Radius : " << radius << endl;
    }
};
class RightTriangle : public Shape
{
    double base;   
    double height;
public:
    RightTriangle() : base(0), height(0), Shape("no name", "Right Triangle", "white") {}
    RightTriangle(string n, string c, double b, double h)
        : base(b), height(h), Shape(n, "Right Triangle", c) {
    }
    double GetArea() const override
    {
        return 0.5 * base * height;
    }
    void Show() const override
    {
        cout << "Right Triangle:" << endl;
        Shape::Show();
        cout << "Cathetus 1 : " << base << endl;
        cout << "Cathetus 2 : " << height << endl;
    }
};
class Triangle : public Shape
{
    double a, b, c;
public:
    Triangle() : a(0), b(0), c(0), Shape("no name", "Triangle", "white") {}
    Triangle(string n, string col, double sideA, double sideB, double sideC)
        : a(sideA), b(sideB), c(sideC), Shape(n, "Triangle", col) {
    }
    double GetArea() const override
    {
        double p = (a + b + c) / 2.0; 
        return sqrt(p * (p - a) * (p - b) * (p - c));
    }
    void Show() const override
    {
        cout << "Triangle:" << endl;
        Shape::Show();
        cout << "Sides : " << a << ", " << b << ", " << c << endl;
    }
};
class Trapezoid : public Shape
{
    double topBase;    
    double bottomBase; 
    double height;     
public:
    Trapezoid() : topBase(0), bottomBase(0), height(0), Shape("no name", "Trapezoid", "white") {}
    Trapezoid(string n, string c, double top, double bottom, double h)
        : topBase(top), bottomBase(bottom), height(h), Shape(n, "Trapezoid", c) {
    }
    double GetArea() const override
    {
        return ((topBase + bottomBase) / 2.0) * height;
    }
    void Show() const override
    {
        cout << "Trapezoid:" << endl;
        Shape::Show();
        cout << "Top base : " << topBase << endl;
        cout << "Bottom base : " << bottomBase << endl;
        cout << "Height : " << height << endl;
    }
};
void TestShape(Shape& shape)
{
    shape.Show();
    cout << "Area : " << shape.GetArea() << endl << endl;
}
int main()
{
    Rectangle rect("Box", "Red", 5, 10);
    Circle circle("Sun", "Yellow", 4);
    RightTriangle rTriangle("Corner", "Blue", 3, 4);
    Triangle triangle("Pyramid", "Green", 5, 6, 7);
    Trapezoid trapezoid("Roof", "Brown", 4, 8, 5);
    TestShape(rect);
    TestShape(circle);
    TestShape(rTriangle);
    TestShape(triangle);
    TestShape(trapezoid);
    cout << "Testing via array of pointers" << endl;
    Shape* shapes[5]{
        new Rectangle("Screen", "Black", 16, 9),
        new Circle("Wheel", "Grey", 7),
        new RightTriangle("Sail", "White", 6, 8),
        new Triangle("Sign", "Orange", 3, 4, 5),
        new Trapezoid("Table", "Wood", 10, 14, 6)
    };
    for (int i = 0; i < 5; i++)
    {
        TestShape(*shapes[i]);
        delete shapes[i];
    }
}
