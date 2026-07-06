#include <iostream>
#include <format>
#include "20260706_Header1_津留健翔.h"
using namespace std;

//回復関数
void Heal(int &playerHp,int heal)
{
	//回復
	playerHp += heal;
}

//HP表示関数
void ScreenHp(int &playerHp)
{
	//現状のHPを表示
	cout << format("プレイヤー\nHP: {}", playerHp) << endl;
}

//入力チェック
int InputCheck(int min, int max)
{
	//変数宣言
	int num;

	cout << format("回復しますか？\n(Yes:{} , No:{})",min,max) << endl;
	while (true)
	{
		cin >> num;

		if (num == min || num == max)
		{
			return num;
			break;
		}
		else
		{
			cout << "誤った数字です。入力しなおしてください。" << endl;
		}
	}
}

//run関数
void Run(int min)
{
	//変数宣言 & 初期化
	int playerHp{ Config::START_HP };
	int select;

	cout << "プレイヤーの行動を選択してください" << endl;

	//入力チェック
	select = InputCheck(Config::SELECT_MIN, Config::SELECT_MAX);

	//回復
	if (select == min)
	{
		Heal(playerHp, Config::HEAL);
	}

	//HP表示
	ScreenHp(playerHp);
}