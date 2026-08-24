#include <iostream>
using namespace std;

int main(void)
{
	//”z—ñ
	int numbers[5] = { 35, 82, 17, 96, 54 };
	int* pNum = numbers;

	int maxNum = *pNum;

	for (int i = 0; i < 5; i++)
	{
		if (maxNum < *(pNum + i))
		{
			maxNum = *(pNum + i);
		}
	}

	cout << "Å‘å’l : " << maxNum;

	return 0;
}