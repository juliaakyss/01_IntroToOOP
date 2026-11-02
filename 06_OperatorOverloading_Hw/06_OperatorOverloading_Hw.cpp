#include <iostream>
using namespace std;
class Array {
private:
    int* arr;
    int size;
public:
    Array() {
        arr = nullptr;
        size = 0;
    }
    explicit Array(int size) {
        if (size > 0) {
            this->size = size;
            arr = new int[size];
            for (int i = 0; i < size; i++) {
                arr[i] = 0;
            }
        }
        else {
            arr = nullptr;
            size = 0;
        }
    }
    Array(const Array& other) {
        this->size = other.size;
        if (this->size > 0 && other.arr != nullptr) {
            this->arr = new int[this->size];
            for (int i = 0; i < this->size; i++) {
                this->arr[i] = other.arr[i];
            }
        }
        else {
            this->arr = nullptr;
        }
    }
    ~Array() {
        if (arr != nullptr) {
            delete[] arr;
            arr = nullptr;
        }
    }
    int& operator[](int index) {
        if (index < 0 || index >= size) {
            cout << "Error: Index " << index << " out of bounds!" << endl;
            static int dummy = 0;
            return (size > 0) ? arr[0] : dummy;
        }
        return arr[index];
    }
    const int& operator[](int index) const {
        if (index < 0 || index >= size) {
            cout << "Error: Index " << index << " out of bounds!" << endl;
            static int dummy = 0;
            return (size > 0) ? arr[0] : dummy;
        }
        return arr[index];
    }
    Array& operator()(int value) {
        for (int i = 0; i < size; i++) {
            arr[i] += value;
        }
        return *this;
    }
    Array& operator=(const Array& other) {
        if (this == &other) return *this;

        if (arr != nullptr) {
            delete[] arr;
        }
        this->size = other.size;
        if (this->size > 0) {
            this->arr = new int[this->size];
            for (int i = 0; i < this->size; i++) {
                this->arr[i] = other.arr[i];
            }
        }
        else {
            this->arr = nullptr;
        }

        return *this;
    }
    int getSize() const {
        return size;
    }
    void InitRandom(int minVal = -20, int maxVal = 20) {
        for (int i = 0; i < size; i++) {
            arr[i] = minVal + rand() % (maxVal - minVal + 1);
        }
    }
    void Show() const {
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};
int main()
{
    srand(time(0));
    cout << "Creating Array of size 10" << endl;
    Array arr(10);
    arr.InitRandom(-20, 20);
    cout << "Initial array: ";
    arr.Show();
    cout << "\nTesting operator []" << endl;
    cout << "Reading elements: arr[0] = " << arr[0] << ", arr[3] = " << arr[3] << endl;
    cout << "Modifying via arr[0] = 100 and arr[3] = 50..." << endl;
    arr[0] = 100; 
    arr[3] = 50;
    cout << "Array after modifications: ";
    arr.Show();
    cout << "\nTesting operator ()" << endl;
    cout << "Increasing all elements by 10 (arr(10))..." << endl;
    arr(10); 
    cout << "Result: ";
    arr.Show();
    cout << "Decreasing all elements by 5 (arr(-5))..." << endl;
    arr(-5);
    cout << "Result: ";
    arr.Show();
}
