// line 149, system pause command, not cross platform
#include <iostream>
#include <stdlib.h>	// for random number
using namespace std;

void drawSeparator(int length)
{
	for (length > 0; length--;)
	{
		cout << "-";
	}
	cout << "\n";
}

void displayMenu(int round, int playerHP, int enemyHP)
{
	system("CLS");
	drawSeparator(20);
	cout << "ROUND " << round << endl;
	cout << "Your HP: " << playerHP;
	cout << "\tEnemy HP: " << enemyHP << endl;
	cout << endl << "1. Attack\n";
	cout << "2. Heal\n";
	cout << "3. Defend\n\n";
	
}

int getChoice(int min, int max)
{
	cout << "What do you do?\n>> ";
	int choice;
	cin >> choice;
	if (choice >= min && choice <= max)
	{
		return choice;
	}
}

int getAttack(int damage)
{
	return rand() % damage;
}

int getHealing(int healing)
{
	return rand() % healing;
}

int getDefence()
{
	return rand() % 5;
}

int chooseWeapon(bool person)
{
	if (person)
	{
		drawSeparator(20);
		cout << "Choose your weapon\n";
		cout << "1. Sword\n";
		cout << "2. Staff\n";
		cout << "3. Battle Axe\n\n";
		return getChoice(1, 3);
	}
	else
	{
		return 1 + (rand() % 2);
	}
	
}

int chooseFood(bool person)
{
	if (person)
	{
		drawSeparator(20);
		cout << "Choose your food\n";
		cout << "1. Sandwich\n";
		cout << "2. Pizza\n";
		cout << "3. Steak\n\n";
		return getChoice(1, 3);
	}
	else
	{
		return 1 + (rand() % 2);
	}

}

int main()
{
	int playerHP = 100, enemyHP = 100, round = 1;

	int playerMaxDamage = 7 + chooseWeapon(1);
	int enemyMaxDamage = 7 + chooseWeapon(0);
	system("cls");
	int playerMaxHeal = 7 + chooseFood(1);
	int enemyMaxHeal = 7 + chooseFood(0);
	system("cls");

	while (playerHP > 0 && enemyHP > 0)
	{
		int playerDF = 0, enemyDF = 0;
		displayMenu(round, playerHP, enemyHP);
		int choice = getChoice(1, 3);
		drawSeparator(20);
		if (choice == 1)
		{
			int damage = getAttack(playerMaxDamage);
			cout << "\nYou attack your ENEMY for " << damage << " damage!";
			enemyHP = enemyHP - (damage - enemyDF);
		}
		else if (choice == 2)
		{
			int heal = getHealing(playerMaxHeal);
			cout << "\nYou heal yourself for " << heal << " points!";
			playerHP += heal;
		}
		else if (choice == 3)
		{
			int defend = getDefence();
			cout << "\nYou defend yourself for " << defend << " points of damage!";
			playerDF = defend;
		}
		int enemyChoice = rand() % 2;
		if (enemyChoice == 0)
		{
			int damage = getAttack(enemyMaxDamage);
			cout << "\nENEMY attacks YOU for " << damage << " damage!";
			playerHP -= damage;
		}
		else if (choice == 1)
		{
			int heal = getHealing(enemyMaxHeal);
			cout << "\nENEMY heals THEMSELF for " << heal << " points!";
			enemyHP += heal;
		}
		else if (choice == 3)
		{
			int defend = getDefence();
			cout << "\nENEMY defends THEMSELF for " << defend << " points of damage!";
			enemyDF = defend;
		}
		round++;
		cout << endl << endl;
		system("pause");

		if (playerHP > 0)
		{
			cout << "\nYou Win!";
		}
		else if (playerHP <= 0)
		{
			cout << "\nYou lose!";
		}
	}
return 0;
}
