#include "Card.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void createCard(int cards[])
{
	int index = 0;
	int number = 0;
	int count = 0;

	for (number = 1; number <= MAX_NUMBER; number++)
	{
		for (count = 0; count < number; count++)
		{
			cards[index] = number;
			index++;
		}
	}
}

void shuffleCard(int cards[])
{
	srand((unsigned int)time(NULL));

	for (int i = 0; i < TOTAL_CARD; i++)
	{
		int randomIndex = rand() % TOTAL_CARD;

		int temp = cards[i];
		cards[i] = cards[randomIndex];
		cards[randomIndex] = temp;
	}
}

void showCard(int cards[])
{
	for (int i = 0; i < GROUP_CARD; i++)
	{
		cout << "[" << cards[i] << "]";
	}

	cout << endl;
}

void showHiddenCard(int cards[])
{
	for (int i = 0; i < GROUP_CARD; i++)
	{
		cout << "[?]";
	}

	cout << endl;
}