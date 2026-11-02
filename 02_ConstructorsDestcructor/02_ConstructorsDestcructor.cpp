#include <iostream>
using namespace std;
struct Coord
{
    int x;
    int y;
};
class Rectangle
{
private:
    int width;
    int height;
    char symbol;
    Coord position;
public:
    Rectangle()
    {
        width = 5;
        height = 3;
        symbol = '*';
        position.x = 0;
        position.y = 0;
    }
    Rectangle(int size)
    {
        if (size > 0)
        {
            width = size;
            height = size;
        }
        else
        {
            cout << "Warning: Invalid size! Setting default (5x5)." << endl;
            width = 5;
            height = 5;
        }
        symbol = '*';
        position.x = 0;
        position.y = 0;
    }
    Rectangle(int w, int h)
    {
        width = (w > 0) ? w : 5;
        height = (h > 0) ? h : 3;
        if (w <= 0 || h <= 0)
        {
            cout << "Warning: Invalid dimensions! Applied default fallback values." << endl;
        }
        symbol = '*';
        position.x = 0;
        position.y = 0;
    }
    void setWidth(int w)
    {
        if (w > 0)
            width = w;
        else
            cout << "Error: Width must be positive!" << endl;
    }
    void setHeight(int h)
    {
        if (h > 0)
            height = h;
        else
            cout << "Error: Height must be positive!" << endl;
    }
    void setSymbol(char s)
    {
        if (s != ' ' && s != '\n' && s != '\t')
            symbol = s;
        else
            cout << "Error: Incorrect symbol!" << endl;
    }

    int getWidth() const { return width; }
    int getHeight() const { return height; }
    char getSymbol() const { return symbol; }
    Coord getPosition() const { return position; }
    void print() const
    {
        for (int i = 0; i < position.y; i++)
            cout << endl;
        for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < position.x; j++)
                cout << ' ';
            for (int j = 0; j < width; j++)
                cout << symbol;
            cout << endl;
        }
    }
    void resize(int dh, int dw)
    {
        if (height + dh > 0 && width + dw > 0)
        {
            height += dh;
            width += dw;
        }
        else
        {
            cout << "Error: Resulting height and width must be greater than 0!" << endl;
        }
    }
    void move(int dx, int dy)
    {
        if (position.x + dx >= 0 && position.y + dy >= 0)
        {
            position.x += dx;
            position.y += dy;
        }
        else
        {
            cout << "Error: Coordinates cannot be negative!" << endl;
        }
    }
};
int main()
{
    cout << "Default Rectangle (r1)" << endl;
    Rectangle r1;
    r1.print();
    cout << "\nSquare Rectangle (r2 - size 4)" << endl;
    Rectangle r2(4);
    r2.print();
    cout << "\nCustom Rectangle (r3 - 8x3, symbol '#', moved to (5, 2))" << endl;
    Rectangle r3(8, 3);
    r3.setSymbol('#');
    r3.move(5, 2);
    r3.print();
    cout << "\nAfter resizing r3 (+2 height, +3 width)" << endl;
    r3.resize(2, 3);
    r3.print();
    cout << "\nAfter moving r3 (+2 X, +1 Y)" << endl;
    r3.move(2, 1);
    r3.print();
    cout << "\nTesting incorrect data validation" << endl;
    cout << "Attempting invalid resize:" << endl;
    r3.resize(-100, -100);
    cout << "Attempting invalid move:" << endl;
    r3.move(-100, -100);
}
