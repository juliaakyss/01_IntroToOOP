#include <iostream>
using namespace std;
class Airplane {
private:
    string model;
    string type;
    int currentPassengers;
    int maxPassengers;
public:
    Airplane() {
        this->model = "Unknown";
        this->type = "Unknown";
        this->currentPassengers = 0;
        this->maxPassengers = 100;
    }
    Airplane(string model, string type, int currentPassengers, int maxPassengers) {
        this->model = model;
        this->type = type;
        this->maxPassengers = (maxPassengers > 0) ? maxPassengers : 100;

        if (currentPassengers < 0) {
            this->currentPassengers = 0;
        }
        else if (currentPassengers > this->maxPassengers) {
            cout << "Warning: Current passengers exceed max capacity! Setting to max (" << this->maxPassengers << ")." << endl;
            this->currentPassengers = this->maxPassengers;
        }
        else {
            this->currentPassengers = currentPassengers;
        }
    }
    string getModel() const { return model; }
    string getType() const { return type; }
    int getCurrentPassengers() const { return currentPassengers; }
    int getMaxPassengers() const { return maxPassengers; }

    void setModel(string model) { this->model = model; }
    void setType(string type) { this->type = type; }

    void setCurrentPassengers(int passengers) {
        if (passengers < 0) {
            cout << "Error: Passengers count cannot be negative!" << endl;
        }
        else if (passengers > maxPassengers) {
            cout << "Error: Passengers count cannot exceed maximum capacity (" << maxPassengers << ")!" << endl;
        }
        else {
            this->currentPassengers = passengers;
        }
    }
    void setMaxPassengers(int maxPass) {
        if (maxPass > 0) {
            this->maxPassengers = maxPass;
            if (this->currentPassengers > this->maxPassengers) {
                this->currentPassengers = this->maxPassengers;
            }
        }
        else {
            cout << "Error: Max capacity must be positive!" << endl;
        }
    }
    void Print() const {
        cout << "Model: " << model
            << " | Type: " << type
            << " | Passengers: " << currentPassengers << "/" << maxPassengers << endl;
    }
    Airplane& operator++() {
        if (this->currentPassengers + 1 <= this->maxPassengers) {
            this->currentPassengers++;
        }
        else {
            cout << "Error (++): Max capacity reached (" << maxPassengers << ")!" << endl;
        }
        return *this;
    }
    Airplane& operator--() {
        if (this->currentPassengers - 1 >= 0) {
            this->currentPassengers--;
        }
        else {
            cout << "Error (--): Passengers count cannot be negative!" << endl;
        }
        return *this;
    }
    Airplane& operator()(int count) {
        if (count < 0) {
            cout << "Error (()): Value must be positive!" << endl;
        }
        else if (this->currentPassengers + count <= this->maxPassengers) {
            this->currentPassengers += count;
        }
        else {
            cout << "Error (()): Adding " << count << " passengers exceeds capacity ("
                << maxPassengers << ")! Current: " << currentPassengers << "." << endl;
        }
        return *this;
    }
    friend bool operator==(const Airplane& left, const Airplane& right);
    friend bool operator>(const Airplane& left, const Airplane& right);
    friend ostream& operator<<(ostream& out, const Airplane& plane);
};
bool operator==(const Airplane& left, const Airplane& right) {
    return left.type == right.type;
}
bool operator>(const Airplane& left, const Airplane& right) {
    return left.maxPassengers > right.maxPassengers;
}
ostream& operator<<(ostream& out, const Airplane& plane) {
    out << "[" << plane.model << " | Type: " << plane.type
        << " | Passengers: " << plane.currentPassengers << "/" << plane.maxPassengers << "]";
    return out;
}
int main()
{
    Airplane plane1("Boeing 737", "Passenger", 150, 180);
    Airplane plane2("Airbus A320", "Passenger", 175, 180);
    Airplane plane3("An-124 Ruslan", "Cargo", 10, 30);
    cout << "Created Airplanes" << endl;
    cout << "Plane 1: " << plane1 << endl;
    cout << "Plane 2: " << plane2 << endl;
    cout << "Plane 3: " << plane3 << endl;
    cout << "\n1. Testing Equality Operator (==) [Friend]" << endl;
    if (plane1 == plane2) {
        cout << "plane1 and plane2 have the SAME type (" << plane1.getType() << ")" << endl;
    }
    else {
        cout << "plane1 and plane2 have DIFFERENT types" << endl;
    }
    if (plane1 == plane3) {
        cout << "plane1 and plane3 have the SAME type" << endl;
    }
    else {
        cout << "plane1 and plane3 have DIFFERENT types" << endl;
    }
    cout << "\n2. Testing Comparison Operator (>) [Friend]" << endl;
    if (plane1 > plane3) {
        cout << "plane1 capacity (" << plane1.getMaxPassengers()
            << ") > plane3 capacity (" << plane3.getMaxPassengers() << ")" << endl;
    }
    cout << "\n3. Testing ++ and --" << endl;
    ++plane1;
    cout << "After ++plane1: " << plane1 << endl;
    --plane1;
    cout << "After --plane1: " << plane1 << endl;
    cout << "\n4. Testing operator() (plane1(15))" << endl;
    plane1(15);
    cout << "After plane1(15): " << plane1 << endl;
    cout << "\n5. Testing Overflow Prevention" << endl;
    plane1(20);
}
