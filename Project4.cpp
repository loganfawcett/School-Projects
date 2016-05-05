#include <iostream>
#include <string>
#include <fstream>
using namespace std;

#include "Menu.hpp"

struct Library
{
	string id;
	string title;
	string first, middle, last;
};

void InitLibrary(Library bookList[80], int bookCount, int& listSize)
{
	ifstream input("library.txt");
	string buffer;

	input >> buffer;
	input >> buffer;
	input >> buffer;

	while (
		input
		>> bookList[bookCount].id
		>> bookList[bookCount].title
		>> bookList[bookCount].first
		>> bookList[bookCount].middle
		>> bookList[bookCount].last
		)
	{
		bookCount++;
	}

	input.close();
}

int MainMenu()
{
	int choice = Menu::ShowMenuWithPrompt({ "Public Access", "Admin Access", "Exit" });
	return choice;
}

int AdminMenu()
{
	int choice = Menu::ShowMenuWithPrompt({ "Update Book", "Add Book", "Export Database" });
	return choice;
}

int PublicMenu()
{
	int choice = Menu::ShowMenuWithPrompt({ "Search by title", "Search by author" });
	return choice;
}

void SearchByTitle(int listSize, Library bookList[80], int bookCount)
{
	cout << "Please enter keyword to search for: ";
	string keyword;
	int book;
	cin >> keyword;
	for (int i = 0; i < listSize; i++)
	{
		if (bookList[i].title.find(keyword) == string::npos)
		{
			cout << "FOUND" << bookList[bookCount].id
				<< bookList[bookCount].title
				<< bookList[bookCount].first
				<< bookList[bookCount].middle
				<< bookList[bookCount].last << endl;
		}
		else
		{
			cout << "NOT FOUND" << endl;
		}
	}
}

void SearchByAuthor(int listSize, Library bookList[80], int bookCount)
{
	cout << "Please enter a name to search for: ";
	string keyword;
	int book;
	cin >> keyword;
	for (int i = 0; i < listSize; i++)
	{
		if (bookList[i].first.find(keyword) == string::npos || bookList[i].middle.find(keyword) == string::npos || bookList[i].last.find(keyword) == string::npos)
		{
			cout << "FOUND" << bookList[bookCount].id
				<< bookList[bookCount].title
				<< bookList[bookCount].first
				<< bookList[bookCount].middle
				<< bookList[bookCount].last << endl;
		}
		else
		{
			cout << "NOT FOUND" << endl;
		}
	}
}

void RunPublic(int listSize, Library bookList[80], int bookCount)
{
	int choice = PublicMenu();
	if (choice == 1)
	{
		SearchByTitle(listSize, bookList, bookCount);
	}
	else
	{
		SearchByAuthor(listSize, bookList, bookCount);
	}
}

void UpdateBook(int index, Library bookList[80])
{
	cout << "Enter book's new title: ";
	cin >> bookList[index].title;

	cout << "Enter author's first, middle, then last name: ";
	cin >> bookList[index].first >> bookList[index].middle >> bookList[index].last;
}

void AddBook(int bookCount, Library bookList[80])
{
	if (bookCount >= 80)
	{
		cout << "Error: Book list is full.";
	}
	else
	{
		UpdateBook(bookCount + 1, bookList);
		bookCount++;
	}
}

void SaveLibrary(Library bookList[80], int bookCount, int listSize)
{
	ofstream output("library.txt");
	output << "ID\tTITLE\tAUTHOR\n";
	for (int i = 0; i < listSize; i++)
	{
		output
			<< bookList[i].id
			<< bookList[i].title
			<< bookList[i].first
			<< bookList[i].middle
			<< bookList[i].last;
	}
	output.close();
}

void RunAdmin(int bookCount, Library bookList[80], int listSize)
{
	int choice = AdminMenu();
	if (choice == 1)
	{
		UpdateBook(bookCount, bookList);
	}
	else if (choice == 2)
	{
		AddBook(bookCount, bookList);
	}
	else
	{
		SaveLibrary(bookList, bookCount, listSize);
	}
}

void Run(int bookCount, Library bookList[80], int listSize)
{
	bool done = false;
	while (!done)
	{
		int choice = MainMenu();
		if (choice == 1)
		{
			RunPublic(bookCount, bookList, listSize);
		}
		else if (choice == 2)
		{
			RunAdmin(bookCount, bookList, listSize);
		}
		else
		{
			break;
		}
	}

}

int SelectBook(int bookCount, Library bookList[80])
{
	int increment = 20;
	int pages = bookCount / increment;
	while (increment > 0)
	{
		for (int p = 0; p <= pages; p++)
		{
			int first = p*increment;
			int last = p*increment + increment;
			for (int n = first; n < last; n++)
			{
				cout << n << "\t" << bookList[n].id
					<< "\t" << "\t" << bookList[n].title
					<< "\t" << bookList[n].first
					<<"\t" << bookList[n].middle
					<< "\t" << bookList[n].last << endl;
			}
			cout << "Enter any number to go to next page.\n";
			int choice;
			cin >> choice;
			if (choice >= first && choice <= last)
			{
				return choice;
			}
		}
	}
}

int main()
{
	Library bookList[80];
	int bookCount = 0;
	int listSize = 80;

	InitLibrary(bookList, bookCount, listSize);
	Run(bookCount, bookList, listSize);
	return 0;
}
