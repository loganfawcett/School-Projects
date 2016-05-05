#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

void Wipe(string titles[], int count, int students[])
{
	for (int i = 0; i < 10; i++)
	{
		titles[i] = "";
		students[i] = 0;
	}
}
int GetUserInput(int min, int max)
{
	cout << "Please select a number between " << min << " and " << max << endl;
	int choice;
	cin >> choice;
	while (choice < min || choice > max)
	{
		cout << "Choice invalid. Try again: ";
		cin >> choice;
	}
	return choice;
}
void DisplayMainMenu()
{
	system("CLS");
	cout << "1.\tAdd class\n";
	cout << "2.\tRemove last class\n";
	cout << "3.\tUpdate class\n";
	cout << "4.\tView all classes\n";
	cout << "5.\tWipe\n";
	cout << "6.\tExit\n";
}
void AddClass(string titles[], int count, int students[])
{
	cout << "Please enter the class name: ";
	cin >> titles[count];
	cout << "Please enter the student amount: ";
	cin >> students[count];
}
void RemoveLastClass(string titles[], int count, int students[])
{
	if (count == 0)
	{
		cout << "No classes exist.\n";
		system("pause");
	}
	else
	{
		count--;
		titles[count] = "";
		students[count] = 0;
	}
}
void ViewAllClasses(string titles[], int count, int students[])
{
	if (count == 0)
	{
		cout << "Class list is empty.\n";
	}
	else
	{
		for (int i = 0; i < count; i++)
		{
			cout << i << "\t" << titles[i] << "\t" << students[i] << endl;
		}
	}
}
void UpdateClass(string titles[], int count, int students[])
{
	ViewAllClasses(titles, count, students);
	if (count == 0)
	{
		system("pause");
	}
	else
	{
		int choice;
		choice = GetUserInput(0, count - 1);
		cout << "Please enter the class name: ";
		cin >> titles[choice];
		cout << "Please enter the student amount: ";
		cin >> students[choice];
	}
}
bool wipeVerify()
{
	cout << "Are you sure you want to wipe all the memory? (y/n)";
	char choice;
	cin >> choice;
	if (choice == 'y')
	{
		return true;
	}
	else
	{
		return false;
	}
}

int main()
{
	string classTitles[10];
	int classStudentCount[10], classCount = 0;
	bool done = false;
	Wipe(classTitles, classCount, classStudentCount);

	while (!done)
	{
		DisplayMainMenu();
		int choice;
		choice = GetUserInput(1, 6);
		if (choice == 1)
		{
			AddClass(classTitles, classCount, classStudentCount);
			classCount++;
		}
		else if (choice == 2)
		{
			RemoveLastClass(classTitles, classCount, classStudentCount);
			classCount--;
		}
		else if (choice == 3)
		{
			UpdateClass(classTitles, classCount, classStudentCount);
		}
		else if (choice == 4)
		{
			ViewAllClasses(classTitles, classCount, classStudentCount);
			system("pause");
		}
		else if (choice == 5)
		{
			bool clear;
			clear = wipeVerify();
			if (clear == true)
			{
				Wipe(classTitles, classCount, classStudentCount);
				classCount = 0;
			}
			
		}
		else if (choice == 6)
		{
			done = true;
		}
	}

	return 0;
}
