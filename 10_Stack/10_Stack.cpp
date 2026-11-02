#include <iostream>
using namespace std;
class CharStackStatic {
private:
    char* arr;          
    int capacity;       
    int topIndex;       
public:
    explicit CharStackStatic(int capacity) {
        if (capacity <= 0) {
            throw invalid_argument("Capacity must be positive!");
        }
        this->capacity = capacity;
        this->arr = new char[this->capacity];
        this->topIndex = -1; 
    }
    ~CharStackStatic() {
        delete[] arr;
    }
    bool IsEmpty() const {
        return topIndex == -1;
    }
    bool IsFull() const {
        return topIndex == capacity - 1;
    }
    bool Push(char ch) {
        if (IsFull()) {
            cout << "Error: Stack overflow! Cannot push '" << ch << "'." << endl;
            return false;
        }
        arr[++topIndex] = ch;
        return true;
    }
    char Pop() {
        if (IsEmpty()) {
            cout << "Error: Stack underflow!" << endl;
            return '\0'; 
        }
        return arr[topIndex--];
    }
    char Peek() const {
        if (IsEmpty()) {
            cout << "Error: Stack is empty!" << endl;
            return '\0';
        }
        return arr[topIndex];
    }
    int GetCount() const {
        return topIndex + 1;
    }
    void Clear() {
        topIndex = -1;
    }
    void Print() const {
        if (IsEmpty()) {
            cout << "Stack is empty." << endl;
            return;
        }
        cout << "Static Stack (Count: " << GetCount() << "/" << capacity << "): ";
        for (int i = 0; i <= topIndex; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};
class CharStackDynamic {
private:
    char* arr;         
    int capacity;      
    int topIndex;       
    void Resize() {
        int newCapacity = capacity * 2;
        char* temp = new char[newCapacity];
        for (int i = 0; i <= topIndex; i++) {
            temp[i] = arr[i];
        }
        delete[] arr;       
        arr = temp;         
        capacity = newCapacity;
        cout << "--> Stack capacity automatically expanded to: " << capacity << endl;
    }
public:
    explicit CharStackDynamic(int initialCapacity = 4) {
        this->capacity = (initialCapacity > 0) ? initialCapacity : 4;
        this->arr = new char[this->capacity];
        this->topIndex = -1;
    }
    CharStackDynamic(const CharStackDynamic&) = delete;
    CharStackDynamic& operator=(const CharStackDynamic&) = delete;
    ~CharStackDynamic() {
        if (arr != nullptr) {
            delete[] arr;
        }
    }
    bool IsEmpty() const {
        return topIndex == -1;
    }
    bool IsFull() const {
        return topIndex == capacity - 1;
    }
    void Push(char ch) {
        if (IsFull()) {
            Resize(); 
        }
        arr[++topIndex] = ch;
    }
    char Pop() {
        if (IsEmpty()) {
            cout << "Error: Stack underflow!" << endl;
            return '\0';
        }
        return arr[topIndex--];
    }
    char Peek() const {
        if (IsEmpty()) {
            cout << "Error: Stack is empty!" << endl;
            return '\0';
        }
        return arr[topIndex];
    }
    int GetCount() const {
        return topIndex + 1;
    }
    void Clear() {
        topIndex = -1;
    }
    int GetCapacity() const {
        return capacity;
    }
    void Print() const {
        if (IsEmpty()) {
            cout << "Stack is empty." << endl;
            return;
        }
        cout << "Dynamic Stack (Count: " << GetCount() << ", Capacity: " << capacity << "): ";
        for (int i = 0; i <= topIndex; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};
int main()
{
    cout << "TEST TASK 1 (STATIC STACK)" << endl;
    CharStackStatic staticStack(5); 
    cout << "Is empty? " << (staticStack.IsEmpty() ? "Yes" : "No") << endl;
    staticStack.Push('A');
    staticStack.Push('B');
    staticStack.Push('C');
    staticStack.Push('D');
    staticStack.Push('E');
    staticStack.Print();
    staticStack.Push('F');
    cout << "Top element (Peek): " << staticStack.Peek() << endl;
    cout << "Popped element: " << staticStack.Pop() << endl;
    staticStack.Print();
    staticStack.Clear();
    cout << "After Clear(), Is empty? " << (staticStack.IsEmpty() ? "Yes" : "No") << endl;
    cout << "\nTEST TASK 2 (DYNAMIC STACK)" << endl;
    CharStackDynamic dynStack(3); 
    dynStack.Push('H');
    dynStack.Push('E');
    dynStack.Push('L');
    dynStack.Print();
    cout << "\nAdding elements beyond initial capacity (3):" << endl;
    dynStack.Push('L');
    dynStack.Push('O');
    dynStack.Push('!');
    dynStack.Print();
    cout << "\nPopping elements:" << endl;
    while (!dynStack.IsEmpty()) {
        cout << "Popped: '" << dynStack.Pop() << "' | Remaining count: " << dynStack.GetCount() << endl;
    }
}
