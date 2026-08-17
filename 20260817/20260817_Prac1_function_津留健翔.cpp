#include <iostream>
using namespace std;

#include "20260817_Prac1_header.h"

/// <summary>
/// プレイヤーが選択した球種名を表示
/// </summary>
/// <param name="piting"></param>
void PitingType(int piting)
{

	switch (piting)
	{
	case 0:
		cout << "ストレートを投げました" << endl;
		break;
	case 1:
		cout << "カーブを投げました" << endl;
		break;
	case 2:
		cout << "スライダーを投げました" << endl;
		break;
	case 3:
		cout << "シンカーを投げました" << endl;
		break;

	}
}

/// <summary>
/// 勝敗結果の表示
/// </summary>
/// <param name="out"></param>
void Result(int out)
{
	if (out >= 3)
	{
		cout << "PLAYER WINNER!!" << endl;
	}
	else
	{
		cout << "CPU WINNER!!" << endl;
	}
}