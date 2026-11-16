#include <iostream>
using namespace std;
class Student {
    string name;
    int age;
    string university;
    string specialty;
public:
    Student() : name("No name"), age(18), university("Unknown"), specialty("General") {}
    Student(string n, int a, string u, string s)
        : name(n), age(a), university(u), specialty(s) {
    }
    string GetName() const {
        return name;
    }
    void Print() const {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "University: " << university << endl;
        cout << "Specialty: " << specialty << endl;
    }
    void Study() {
        cout << name << " is studying " << specialty << "..." << endl;
    }
};
class Aspirant : public Student {
    string thesisTopic; 
    int writtenPages;   
    bool isDefended;   
public:
    Aspirant() : thesisTopic("No topic"), writtenPages(0), isDefended(false), Student() {}
    Aspirant(string n, int a, string u, string s, string topic, int pages = 0)
        : thesisTopic(topic), writtenPages(pages), isDefended(false), Student(n, a, u, s) {
    }
    void WriteDissertation(int pages) {
        if (pages > 0) {
            writtenPages += pages;
            cout << GetName() << " wrote " << pages << " pages. Total pages: " << writtenPages << endl;
        }
        else {
            cout << "Number of pages must be positive!" << endl;
        }
    }
    void DefendDissertation() {
        cout << "\n Defense Process for " << GetName() << endl;
        cout << "Topic: \"" << thesisTopic << "\"" << endl;
        if (writtenPages >= 100) {
            isDefended = true;
            cout << "Congratulations! " << GetName() << " successfully defended the dissertation ("
                << writtenPages << " pages) and earned a PhD!" << endl;
        }
        else {
            cout << "Defense failed! Not enough pages written (" << writtenPages
                << "/100). Need to write " << (100 - writtenPages) << " more pages." << endl;
        }
    }
    void Print() const {
        cout << "Aspirant:" << endl;
        Student::Print(); 
        cout << "Thesis Topic: " << thesisTopic << endl;
        cout << "Written Pages: " << writtenPages << endl;
        cout << "Status: " << (isDefended ? "PhD (Defended)" : "In progress") << endl;
    }
};
int main()
{
    cout << "Student:" << endl;
    Student student("Ivan Petrenko", 20, "KPI", "Computer Science");
    student.Print();
    student.Study();
    cout << endl;
    Aspirant aspirant("Olena Kovalenko", 25, "LNU", "Applied Mathematics", "Artificial Intelligence in Medicine", 40);
    aspirant.Print();
    cout << "\nWorking on dissertation:" << endl;
    aspirant.DefendDissertation();
    aspirant.WriteDissertation(35);
    aspirant.WriteDissertation(30);
    aspirant.DefendDissertation();
    cout << endl;
    aspirant.Print();
}
