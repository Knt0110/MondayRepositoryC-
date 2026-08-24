#include <iostream>
using namespace std;

const int SIZE{ 5 };

void Calculation(int num[],int input)
{
	
}

void ShowNumbers(int num[])
{
	for (int i = 0; i < SIZE; i++)
	{
		cout << num[i] << endl;
	}
}

int main(void)
{
	//変数宣言＆配列
	int numbers[SIZE] = { 10,20,30,40,50 };
	int* pNum = numbers;

	int inputNum;
	
	//入力前数字出力
	ShowNumbers(pNum);

	//数字入力
	cout << "\n\n入力（乗算）\n→ ";
	cin >> inputNum;

	//入力された数字を関数に入れて計算する
	Calculation(pNum,inputNum);

	return 0;
}