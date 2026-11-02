#include <iostream>
#include <fstream>
using namespace std;
class Point
{
private:
    double x;
    double y;
    double z;
public:
    Point()
    {
        x = 0;
        y = 0;
        z = 0;
    }
    void setX(double x)
    {
        this->x = x;
    }
    void setY(double y)
    {
        this->y = y;
    }
    void setZ(double z)
    {
        this->z = z;
    }
    double getX()
    {
        return x;
    }
    double getY()
    {
        return y;
    }
    double getZ()
    {
        return z;
    }
    void Init()
    {
        cout << "Enter X: "; cin >> x;
        cout << "Enter Y: "; cin >> y;
        cout << "Enter Z: "; cin >> z;
    }
    void Print()
    {
        cout << "Point coordinates: X = " << x << ", Y = " << y << ", Z = " << z << endl;
    }
    void SaveToFile(string filename)
    {
        ofstream fout(filename);
        if (fout.is_open())
        {
            fout << x << " " << y << " " << z;
            fout.close();
            cout << "Data saved to " << filename << " successfully." << endl;
        }
        else
        {
            cout << "Error opening file for writing!" << endl;
        }
    }
    void LoadFromFile(string filename)
    {
        ifstream fin(filename);
        if (fin.is_open())
        {
            fin >> x >> y >> z;
            fin.close();
            cout << "Data loaded from " << filename << " successfully." << endl;
        }
        else
        {
            cout << "Error opening file for reading!" << endl;
        }
    }
};
int main()
{
    Point p1;
    cout << "Entering point data:" << endl;
    p1.Init();
    cout << "\nDisplaying point data" << endl;
    p1.Print();
    p1.setX(15.5);
    cout << "Updated X coordinate via getter: " << p1.getX() << endl;
    cout << "\nSaving to file" << endl;
    p1.SaveToFile("point.txt");
    cout << "\nLoading from file into new Point" << endl;
    Point p2;
    p2.LoadFromFile("point.txt");
    p2.Print();
}
