#include <iostream>
using namespace std;
class Employer 
{
    string name;
    int age;
    float salary;
public:
    Employer() : name("no name"), age(0), salary(0) {}
    Employer(string n, int a, float s) : name(n)
    {
        age = (a > 0) ? a : 0;
        salary = (s > 0) ? s : 0;
    }
    void ShowBaseInfo() const
    {
        cout << "Name : " << name << endl;
        cout << "Age : " << age << endl;
        cout << "Salary : " << salary << "$" << endl;
    }
    virtual void Print() const = 0; 
};
class President : public Employer
{
    string companyName;
    int experienceYears;
public:
    President() : companyName("no company"), experienceYears(0), Employer() {}
    President(string n, int a, float s, string c, int exp)
        : companyName(c), Employer(n, a, s)
    {
        experienceYears = (exp > 0) ? exp : 0;
    }
    void Print() const override
    {
        cout << "President:" << endl;
        Employer::ShowBaseInfo();
        cout << "Company : " << companyName << endl;
        cout << "Management experience : " << experienceYears << " years" << endl;
    }
};
class Manager : public Employer
{
    string department;
    int teamSize;
public:
    Manager() : department("no department"), teamSize(0), Employer() {}
    Manager(string n, int a, float s, string dep, int team)
        : department(dep), Employer(n, a, s)
    {
        teamSize = (team > 0) ? team : 0;
    }
    void Print() const override
    {
        cout << "Manager:" << endl;
        Employer::ShowBaseInfo();
        cout << "Department : " << department << endl;
        cout << "Subordinates count : " << teamSize << endl;
    }
};
class Worker : public Employer
{
    string position;
    int hoursPerWeek;
public:
    Worker() : position("no position"), hoursPerWeek(0), Employer() {}
    Worker(string n, int a, float s, string pos, int hours)
        : position(pos), Employer(n, a, s)
    {
        hoursPerWeek = (hours > 0) ? hours : 0;
    }
    void Print() const override
    {
        cout << "Worker:" << endl;
        Employer::ShowBaseInfo();
        cout << "Position : " << position << endl;
        cout << "Work hours per week : " << hoursPerWeek << "h" << endl;
    }
};
void ShowEmployer(const Employer& emp)
{
    emp.Print();
    cout << endl;
}
int main()
{
    President president("Oleg Kovalenko", 45, 15000, "TechCorp", 15);
    president.Print();
    cout << endl;
    Manager manager("Anna Melnyk", 32, 4500, "IT Development", 12);
    manager.Print();
    cout << endl;
    Worker worker("Ivan Petrenko", 26, 2000, "Software Engineer", 40);
    worker.Print();
    cout << endl;
    ShowEmployer(president);
    ShowEmployer(manager);
    ShowEmployer(worker);
}
