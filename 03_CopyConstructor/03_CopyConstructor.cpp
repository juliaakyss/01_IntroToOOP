#include <iostream>
using namespace std;
class Array {
private:
	long* arr;
	int size;
public:
	Array()
	{
		this->size = 0;
		this->arr = nullptr;
	}
	Array(int size)
	{
		if (size <= 0)
		{
			this->size = 0;
			this->arr = nullptr;
		}
		else
		{
			this->size = size;
			this->arr = new long[this->size];
			for (int i = 0; i < this->size; i++)
			{
				this->arr[i] = 0;
			}
		}
	}
	Array(const Array& other)
	{
		this->size = other.size;
		if (this->size > 0 && other.arr != nullptr)
		{
			this->arr = new long[this->size];
			for (int i = 0; i < this->size; i++)
			{
				this->arr[i] = other.arr[i];
			}
		}
		else
		{
			this->arr = nullptr;
		}
	}
	~Array()
	{
		if (this->arr != nullptr)
		{
			delete[] this->arr;
			this->arr = nullptr;
		}
	}
	void fillRandom(long minVal = 1, long maxVal = 100)
	{
		if (this->size <= 0 || this->arr == nullptr)
		{
			cout << "Error: Array is empty! Cannot fill." << endl;
			return;
		}
		for (int i = 0; i < this->size; i++)
		{
			this->arr[i] = minVal + rand() % (maxVal - minVal + 1);
		}
	}
	void fillFromKeyboard()
	{
		if (this->size <= 0 || this->arr == nullptr)
		{
			cout << "Error: Array is empty! Cannot fill." << endl;
			return;
		}
		cout << "Enter " << this->size << " elements:" << endl;
		for (int i = 0; i < this->size; i++)
		{
			cout << "arr[" << i << "] = ";
			cin >> this->arr[i];
		}
	}
	void fillDefault(long defaultValue = 0)
	{
		if (this->size <= 0 || this->arr == nullptr)
		{
			cout << "Error: Array is empty! Cannot fill." << endl;
			return;
		}
		for (int i = 0; i < this->size; i++)
		{
			this->arr[i] = defaultValue;
		}
	}
	void print() const
	{
		if (this->size <= 0 || this->arr == nullptr)
		{
			cout << "Array is empty." << endl;
			return;
		}
		cout << "Array (size = " << this->size << "): [ ";
		for (int i = 0; i < this->size; i++)
		{
			cout << this->arr[i] << " ";
		}
		cout << "]" << endl;
	}
	void add(long value)
	{
		long* temp = new long[this->size + 1];
		for (int i = 0; i < this->size; i++)
		{
			temp[i] = this->arr[i];
		}
		temp[this->size] = value;

		if (this->arr != nullptr)
		{
			delete[] this->arr;
		}

		this->arr = temp;
		this->size++;
	}
	bool removeByIndex(int index)
	{
		if (index < 0 || index >= this->size || this->arr == nullptr)
		{
			cout << "Error: Invalid index " << index << " for deletion!" << endl;
			return false;
		}
		if (this->size == 1)
		{
			delete[] this->arr;
			this->arr = nullptr;
			this->size = 0;
			return true;
		}
		long* temp = new long[this->size - 1];
		for (int i = 0, j = 0; i < this->size; i++)
		{
			if (i != index)
			{
				temp[j++] = this->arr[i];
			}
		}
		delete[] this->arr;
		this->arr = temp;
		this->size--;
		return true;
	}
	bool removeByValue(long value)
	{
		int index = -1;
		for (int i = 0; i < this->size; i++)
		{
			if (this->arr[i] == value)
			{
				index = i;
				break;
			}
		}
		if (index == -1)
		{
			cout << "Error: Value " << value << " not found in array!" << endl;
			return false;
		}

		return removeByIndex(index);
	}
	void sort(bool isAscending = true)
	{
		if (this->size <= 1 || this->arr == nullptr) return;

		for (int i = 0; i < this->size - 1; i++)
		{
			for (int j = 0; j < this->size - i - 1; j++)
			{
				bool condition = isAscending ? (this->arr[j] > this->arr[j + 1])
					: (this->arr[j] < this->arr[j + 1]);
				if (condition)
				{
					long temp = this->arr[j];
					this->arr[j] = this->arr[j + 1];
					this->arr[j + 1] = temp;
				}
			}
		}
	}
	long getMin() const
	{
		if (this->size <= 0 || this->arr == nullptr)
		{
			cout << "Error: Array is empty!" << endl;
			return 0;
		}
		long minVal = this->arr[0];
		for (int i = 1; i < this->size; i++)
		{
			if (this->arr[i] < minVal)
				minVal = this->arr[i];
		}
		return minVal;
	}
	long getMax() const
	{
		if (this->size <= 0 || this->arr == nullptr)
		{
			cout << "Error: Array is empty!" << endl;
			return 0;
		}
		long maxVal = this->arr[0];
		for (int i = 1; i < this->size; i++)
		{
			if (this->arr[i] > maxVal)
				maxVal = this->arr[i];
		}
		return maxVal;
	}
	double getAverage() const
	{
		if (this->size <= 0 || this->arr == nullptr)
		{
			cout << "Error: Array is empty!" << endl;
			return 0.0;
		}
		double sum = 0;
		for (int i = 0; i < this->size; i++)
		{
			sum += this->arr[i];
		}
		return sum / this->size;
	}
	int getSize() const
	{
		return this->size;
	}
};
int main()
{
	srand(time(0));
	cout << "1. Testing Default Constructor" << endl;
	Array arr1;
	arr1.print();
	arr1.add(15);
	arr1.add(42);
	arr1.print();
	cout << "\n2. Testing Parameterized Constructor & Random Fill" << endl;
	Array arr2(6);
	arr2.fillRandom(1, 50);
	arr2.print();
	cout << "\n3. Testing Copy Constructor" << endl;
	Array arrCopy = arr2; 
	cout << "Original (arr2): ";
	arr2.print();
	cout << "Copy (arrCopy):  ";
	arrCopy.print();
	arr2.add(999);
	cout << "\nAfter modifying arr2:" << endl;
	cout << "Original (arr2): ";
	arr2.print();
	cout << "Copy (arrCopy):  ";
	arrCopy.print();
	cout << "\n4. Testing Min, Max, Average" << endl;
	cout << "Min value: " << arrCopy.getMin() << endl;
	cout << "Max value: " << arrCopy.getMax() << endl;
	cout << "Average:   " << arrCopy.getAverage() << endl;
	cout << "\n5. Testing Sorting" << endl;
	cout << "Sorting Ascending:" << endl;
	arrCopy.sort(true);
	arrCopy.print();
	cout << "Sorting Descending:" << endl;
	arrCopy.sort(false);
	arrCopy.print();
	cout << "\n6. Testing Deletion (by Index & Value)" << endl;
	cout << "Deleting index 0:" << endl;
	arrCopy.removeByIndex(0);
	arrCopy.print();
	long firstVal = arrCopy.getMin();
	cout << "Deleting by value (" << firstVal << "):" << endl;
	arrCopy.removeByValue(firstVal);
	arrCopy.print();
	cout << "\n7. Testing Error Handling" << endl;
	arrCopy.removeByIndex(100);  
	arrCopy.removeByValue(9999); 
}
