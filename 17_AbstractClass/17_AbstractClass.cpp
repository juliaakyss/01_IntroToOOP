#include <iostream>
using namespace std;
//class Employer 
//{
//    string name;
//    int age;
//    float salary;
//public:
//    Employer() : name("no name"), age(0), salary(0) {}
//    Employer(string n, int a, float s) : name(n)
//    {
//        age = (a > 0) ? a : 0;
//        salary = (s > 0) ? s : 0;
//    }
//    void ShowBaseInfo() const
//    {
//        cout << "Name : " << name << endl;
//        cout << "Age : " << age << endl;
//        cout << "Salary : " << salary << "$" << endl;
//    }
//    virtual void Print() const = 0; 
//};
//class President : public Employer
//{
//    string companyName;
//    int experienceYears;
//public:
//    President() : companyName("no company"), experienceYears(0), Employer() {}
//    President(string n, int a, float s, string c, int exp)
//        : companyName(c), Employer(n, a, s)
//    {
//        experienceYears = (exp > 0) ? exp : 0;
//    }
//    void Print() const override
//    {
//        cout << "President:" << endl;
//        Employer::ShowBaseInfo();
//        cout << "Company : " << companyName << endl;
//        cout << "Management experience : " << experienceYears << " years" << endl;
//    }
//};
//class Manager : public Employer
//{
//    string department;
//    int teamSize;
//public:
//    Manager() : department("no department"), teamSize(0), Employer() {}
//    Manager(string n, int a, float s, string dep, int team)
//        : department(dep), Employer(n, a, s)
//    {
//        teamSize = (team > 0) ? team : 0;
//    }
//    void Print() const override
//    {
//        cout << "Manager:" << endl;
//        Employer::ShowBaseInfo();
//        cout << "Department : " << department << endl;
//        cout << "Subordinates count : " << teamSize << endl;
//    }
//};
//class Worker : public Employer
//{
//    string position;
//    int hoursPerWeek;
//public:
//    Worker() : position("no position"), hoursPerWeek(0), Employer() {}
//    Worker(string n, int a, float s, string pos, int hours)
//        : position(pos), Employer(n, a, s)
//    {
//        hoursPerWeek = (hours > 0) ? hours : 0;
//    }
//    void Print() const override
//    {
//        cout << "Worker:" << endl;
//        Employer::ShowBaseInfo();
//        cout << "Position : " << position << endl;
//        cout << "Work hours per week : " << hoursPerWeek << "h" << endl;
//    }
//};
//void ShowEmployer(const Employer& emp)
//{
//    emp.Print();
//    cout << endl;
//}
//int main()
//{
//    President president("Oleg Kovalenko", 45, 15000, "TechCorp", 15);
//    president.Print();
//    cout << endl;
//    Manager manager("Anna Melnyk", 32, 4500, "IT Development", 12);
//    manager.Print();
//    cout << endl;
//    Worker worker("Ivan Petrenko", 26, 2000, "Software Engineer", 40);
//    worker.Print();
//    cout << endl;
//    ShowEmployer(president);
//    ShowEmployer(manager);
//    ShowEmployer(worker);
//}

//task2
class Transport
{
private:
    string name;
protected:
    float speed;             
    float passengerRate;    
    float cargoRate;         
public:
    Transport() : name("no name"), speed(0), passengerRate(0), cargoRate(0) {}
    Transport(string n, float s, float pRate, float cRate) : name(n)
    {
        speed = (s > 0) ? s : 1;
        passengerRate = (pRate >= 0) ? pRate : 0;
        cargoRate = (cRate >= 0) ? cRate : 0;
    }
    virtual float CalculateTime(float distance) const
    {
        return distance / speed;
    }
    virtual float CalculateCost(float distance, int passengers, float cargoWeight) const = 0;
    virtual void Show() const
    {
        cout << "Transport : " << name << endl;
        cout << "Speed : " << speed << " km/h" << endl;
    }
};
class Car : public Transport
{
    float fuelConsumption;
public:
    Car() : fuelConsumption(0), Transport() {}
    Car(string n, float s, float pRate, float cRate, float fuel)
        : Transport(n, s, pRate, cRate)
    {
        fuelConsumption = (fuel > 0) ? fuel : 0;
    }
    float CalculateCost(float distance, int passengers, float cargoWeight) const override
    {
        return distance * (passengers * passengerRate + cargoWeight * cargoRate);
    }
    void Show() const override
    {
        cout << "Car:" << endl;
        Transport::Show();
        cout << "Fuel consumption : " << fuelConsumption << " L/100km" << endl;
    }
};
class Bicycle : public Transport
{
    int maxPassengers; 
public:
    Bicycle() : maxPassengers(1), Transport() {}
    Bicycle(string n, float s, float pRate, float cRate, int maxP = 1)
        : Transport(n, s, pRate, cRate)
    {
        maxPassengers = (maxP > 0) ? maxP : 1;
    }
    float CalculateCost(float distance, int passengers, float cargoWeight) const override
    {
        if (passengers > maxPassengers)
        {
            cout << "[Warning: Bicycle cannot carry more than " << maxPassengers << " passenger(s)!] ";
        }
        return distance * (passengers * passengerRate + cargoWeight * cargoRate);
    }
    void Show() const override
    {
        cout << "Bicycle:" << endl;
        Transport::Show();
        cout << "Max passengers : " << maxPassengers << endl;
    }
};
class Cart : public Transport
{
    int horsesCount; 
public:
    Cart() : horsesCount(1), Transport() {}
    Cart(string n, float s, float pRate, float cRate, int horses)
        : Transport(n, s, pRate, cRate)
    {
        horsesCount = (horses > 0) ? horses : 1;
    }
    float CalculateCost(float distance, int passengers, float cargoWeight) const override
    {
        float baseCost = distance * (passengers * passengerRate + cargoWeight * cargoRate);
        return baseCost * horsesCount;
    }
    void Show() const override
    {
        cout << "Cart:" << endl;
        Transport::Show();
        cout << "Horses count : " << horsesCount << endl;
    }
};
void TestTrip(const Transport& transport, float distance, int passengers, float cargoWeight)
{
    transport.Show();
    cout << "Distance : " << distance << " km | Passengers : " << passengers << " | Cargo : " << cargoWeight << " kg" << endl;
    cout << "Trip time : " << transport.CalculateTime(distance) << " hours" << endl;
    cout << "Trip cost : " << transport.CalculateCost(distance, passengers, cargoWeight) << " UAH" << endl;
    cout << endl;
}
int main()
{
    Car car("Toyota Camry", 90, 2.5, 0.1, 8.5);
    Bicycle bike("Trek Marlin", 20, 0.5, 0.05, 1);
    Cart cart("Wooden Cart", 10, 1.0, 0.08, 2);
    TestTrip(car, 45, 2, 30);
    TestTrip(bike, 45, 2, 30);
    TestTrip(cart, 45, 2, 30);
}
