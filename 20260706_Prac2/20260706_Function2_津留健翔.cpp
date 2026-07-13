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

	int round{ 0 };
	int playerHand, cpuHand;

	//乱数初期化
	srand((unsigned int)time(NULL));

	//インフォメーション
	cout << "＝＝＝＝＝＝＝＝じゃんけんゲーム＝＝＝＝＝＝＝＝\n"
		<< "CPUとじゃんけんを行います。\n"
		<< "勝利すると経験値を獲得します。\n"
		<< "一定値に達するとゲームクリアです。\n" 
		<< "＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝" << endl;

	while (true)
	{
		//じゃんけんバトル
		cout << format("第{}ラウンド", round + 1) << endl;
		StatusOpen(playerLv, playerExp);

		//入力
		cout << "1: グー 2: チョキ 3:パー\n";
		playerHand = InputCheck(GameSys::SELECT_MIN,GameSys::SELECT_MAX);

		//CPUの手
		cpuHand = rand() % GameSys::SELECT_MAX + GameSys::SELECT_MIN;
		switch (cpuHand)
		{
		case Hands::rock:
			cout << "CPU: グー\n";
			break;
		case Hands::scissor:
			cout << "CPU: チョキ\n";
			break;
		case Hands::paper:
			cout << "CPU: パー\n";
		}

		//勝敗
		Result result = Judgement(playerHand, cpuHand);

		//勝利時
		if (result == playerWin)
		{
			//経験値獲得
			playerExp += GetExp(playerExp, GameSys::GET_EXP_MIN, GameSys::GET_EXP_MAX);

			//レベルアップ
			playerLv = LvUp(playerLv, playerExp, PlayerStatus::LVUP_EXP);
		}

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
	//変数宣言 & 獲得経験値
	int getExp{ rand() % (expMax)+expMin };

	//獲得通知
	cout << format("経験値を{}獲得しました！", getExp) << endl;

	return getExp;
}

int LvUp(int &lv, int &exp, int maxExp)
{
	if (exp >= maxExp)
	{
		lv++;
		exp -= maxExp;
		cout << format("レベルアップ！\nLv{}になりました。\n", lv) << endl;
	}
	return lv;
}


void StatusOpen(int playerLv,int playerExp)
{
	cout << "========================\n"
		<< "Lv : " << playerLv
		<< "\nEXP : " << playerExp
		<< "\n========================" << endl;
}

int InputCheck(int min, int max)
{
	int num;

	while (true)
	{
		cout << "入力: ";
		cin >> num;

		if (num < min || num > max)
		{
			cout << "範囲外です。再度入力してください。\n";
		}
		else
		{
			break;
		}
	}

	return num;
}

Result Judgement(int player, int cpu)
{
	int num = (cpu - player + GameSys::HAND_NUM) % GameSys::HAND_NUM;

	// 計算結果を enum Result に変換
	Result result = static_cast<Result>(num);

	// 結果を画面に表示する
	if (result == playerWin) {
		cout << "あなたの勝ち！\n";
	}
	else if (result == cpuWin) {
		cout << "CPUの勝ち....\n";
	}
	else {
		cout << "あいこ..\n";
	}
	cout << "\n";
	return result;
}