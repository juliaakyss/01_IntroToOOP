#include <iostream>
using namespace std;
class Book
{
private:
	string author;
	string title;
	string publisher;
	int year;
	int pages;

public:
	Book()
	{
		author = "Unknown";
		title = "Untitled";
		publisher = "Unknown";
		year = 0;
		pages = 0;
	}
	explicit Book(string author, string title, string publisher, int year, int pages)
	{
		this->author = author;
		this->title = title;
		this->publisher = publisher;
		this->year = (year > 0) ? year : 0;
		this->pages = (pages > 0) ? pages : 0;
	}
	string getAuthor() const
	{
		return author;
	}

	string getTitle() const
	{
		return title;
	}

	string getPublisher() const
	{
		return publisher;
	}

	int getYear() const
	{
		return year;
	}

	int getPages() const
	{
		return pages;
	}
	void Print() const
	{
		cout << "----------------------------------------" << endl;
		cout << "Title:     \"" << title << "\"" << endl;
		cout << "Author:    " << author << endl;
		cout << "Publisher: " << publisher << endl;
		cout << "Year:      " << year << endl;
		cout << "Pages:     " << pages << endl;
	}
};
void printBooksByAuthor(const Book books[], int size, const string& author)
{
	cout << "\nBooks by author: \"" << author << "\"" << endl;
	bool found = false;
	for (int i = 0; i < size; i++)
	{
		if (books[i].getAuthor() == author)
		{
			books[i].Print();
			found = true;
		}
	}
	if (!found)
	{
		cout << "No books found by this author." << endl;
	}
}
void printBooksByPublisher(const Book books[], int size, const string& publisher)
{
	cout << "\nBooks by publisher: \"" << publisher << "\"" << endl;
	bool found = false;
	for (int i = 0; i < size; i++)
	{
		if (books[i].getPublisher() == publisher)
		{
			books[i].Print();
			found = true;
		}
	}
	if (!found)
	{
		cout << "No books found by this publisher." << endl;
	}
}
void printBooksAfterYear(const Book books[], int size, int year)
{
	cout << "\nBooks published after " << year << " year" << endl;
	bool found = false;
	for (int i = 0; i < size; i++)
	{
		if (books[i].getYear() > year)
		{
			books[i].Print();
			found = true;
		}
	}
	if (!found)
	{
		cout << "No books found published after this year." << endl;
	}
}
int main()
{
	const int SIZE = 5;
	Book library[SIZE] = {
		Book("Taras Shevchenko", "Kobzar", "Dnipro", 1985, 640),
		Book("Ivan Franko", "Zakhar Berkut", "Ababahalamaha", 2015, 240),
		Book("Lesya Ukrainka", "Lisova Pisnya", "Knowles", 2005, 180),
		Book("Ivan Franko", "Ukradene Shchastya", "Dnipro", 1998, 150),
		Book("George Orwell", "1984", "Ababahalamaha", 2021, 320)
	};
	printBooksByAuthor(library, SIZE, "Ivan Franko");
	printBooksByPublisher(library, SIZE, "Ababahalamaha");
	printBooksAfterYear(library, SIZE, 2000);
}