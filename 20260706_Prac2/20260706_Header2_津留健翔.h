#pragma once

//グローバル関数化
void Game();

int GetExp(int exp, int expMin, int expMax);

int LvUp(int lv, int exp, int maxExp);

void Battle();

//プレイヤーのステータス
namespace PlayerStatus
{
	const int START_LV{ 1 };
	const int LVUP_EXP{ 20 };
	const int END_LV{ 5 };
}

//システム
namespace GameSys
{
	const int SELECT_MIN{ 1 };
	const int SELECT_MAX{ 3 };
	const int GET_EXP_MIN{ 1 };
	const int GET_EXP_MAX{ 15 };
}