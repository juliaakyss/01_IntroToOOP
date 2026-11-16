#include <iostream>
using namespace std;
class Passport {
    string fullName;
    string birthDate;
    string passportNumber;
    string taxId;
public:
    Passport() : fullName("no name"), birthDate("01.01.2000"), passportNumber("000000000"), taxId("0000000000") {}
    Passport(string name, string bDate, string pNum, string tId)
        : fullName(name), birthDate(bDate), passportNumber(pNum), taxId(tId) {
    }
    void Print() const
    {
        cout << "Full name : " << fullName << endl;
        cout << "Birth date : " << birthDate << endl;
        cout << "Passport number : " << passportNumber << endl;
        cout << "Tax ID : " << taxId << endl;
    }
};
class ForeignPassport : public Passport
{
    string foreignNumber;
    string visas;
public:
    ForeignPassport() : foreignNumber("XX000000"), visas("none"), Passport() {}
    ForeignPassport(string name, string bDate, string pNum, string tId, string fNum, string v = "none")
        : foreignNumber(fNum), visas(v), Passport(name, bDate, pNum, tId) {
    }
    void AddVisa(string newVisa)
    {
        if (visas == "none")
            visas = newVisa;
        else
            visas += ", " + newVisa;
    }
    void Print() const
    {
        cout << "Foreign Passport:" << endl;
        Passport::Print();
        cout << "Foreign passport number : " << foreignNumber << endl;
        cout << "Visas : " << visas << endl;
    }
};
int main()
{
    cout << "Passport:" << endl;
    Passport pass("Shevchenko Taras", "09.03.1814", "001234567", "1234567890");
    pass.Print();
    ForeignPassport fPass("Kovalenko Olena", "15.05.1995", "009876543", "0987654321", "FG554433");
    fPass.Print();
    fPass.AddVisa("USA");
    fPass.AddVisa("UK");
    fPass.Print();
}
