#include <iostream>
#include <format>
#include <cstdlib>
#include <ctime>
#include "20260706_Header2_津留健翔.h"
using namespace std;

void Game()
{
	//変数宣言
	int playerLv{ PlayerStatus::START_LV };
	int playerExp{ 0 };

	//インフォメーション
	cout << "＝＝＝＝＝＝＝＝じゃんけんゲーム＝＝＝＝＝＝＝＝\n"
		<< "CPUとじゃんけんを行います。\n"
		<< "勝利すると経験値を獲得します。\n"
		<< "一定値に達するとゲームクリアです。\n" 
		<< "＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝" << endl;

	while (true)
	{
		//じゃんけんバトル
		Battle();

		//経験値獲得
		playerExp += GetExp(playerExp, GameSys::GET_EXP_MIN, GameSys::GET_EXP_MAX);

		//レベルアップ
		LvUp(playerLv, playerExp, PlayerStatus::LVUP_EXP);

		//終了条件
		if (playerLv >= PlayerStatus::END_LV)
		{
			cout << "\n＝＝＝ゲームクリア！！＝＝＝\n"
				<< format("プレイヤーレベルが {} に到達しました。", PlayerStatus::END_LV) << endl;
			break;
		}
	}
}

int GetExp(int exp, int expMin, int expMax)
{
	//乱数初期化
	srand((unsigned int)time(NULL));

	//変数宣言 & 獲得経験値
	int getExp{ rand() % (expMax)+expMin };

	//獲得通知
	cout << format("経験値を{}獲得しました！", getExp) << endl;

	return getExp;
}

int LvUp(int lv, int exp, int maxExp)
{
	if (exp >= maxExp)
	{
		lv++;
		exp -= maxExp;
		cout << format("レベルアップ！\nLv{}になりました。", lv) << endl;
	}
	return lv;
}

void Battle()
{
	//変数宣言
	int round{ 0 };

	cout << format("第{}ラウンド", round + 1) << endl;
}