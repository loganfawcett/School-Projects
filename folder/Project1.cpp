#include <iostream> // I/O Streaming (input/output)
using namespace std;

int main()
{
		cout << "FRACTION 1" << endl;	//Input first fraction

	int n1;
	cout << "Enter the numerator:   ";
	cin >> n1;

	int d1;
	cout << "Enter the denominator: ";
	cin >> d1;

	cout << endl << "FRACTION 2" << endl;	//Input second fraction

	int n2;
	cout << "Enter the numerator:   ";
	cin >> n2;

	int d2;
	cout << "Enter the denominator: ";
	cin >> d2;

	cout << endl << "Results" << endl;
	cout << n1 << "/" << d1 << " times " << n2 << "/" << d2 << " = " << n1*n2 << "/" << d1*d2 << endl;	//Times
	cout << n1 << "/" << d1 << " divided by " << n2 << "/" << d2 << " = " << n1*d2 << "/" << n2*d1 << endl; //Divided
	cout << n1 << "/" << d1 << " plus " << n2 << "/" << d2 << " = " << (n1*d2)+(n2*d1) << "/" << (d1*d2); //Plus

	return 0;
}
