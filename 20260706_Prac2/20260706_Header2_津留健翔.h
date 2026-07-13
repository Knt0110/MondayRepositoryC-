#pragma once
//じゃんけんの手
enum Hands
{
	rock = 1,
	scissor = 2,
	paper = 3
};

//勝敗結果
enum Result
{
	draw,
	playerWin,
	cpuWin
};

//グローバル関数化

/// <summary>
/// ゲームの関数
/// </summary>
void Game();

/// <summary>
/// 経験値獲得関数
/// </summary>
/// <param name="exp"></param>
/// <param name="expMin"></param>
/// <param name="expMax"></param>
/// <returns></returns>
int GetExp(int exp, int expMin, int expMax);

/// <summary>
/// レベルアップ関数
/// </summary>
/// <param name="lv"></param>
/// <param name="exp"></param>
/// <param name="maxExp"></param>
/// <returns></returns>
int LvUp(int &lv, int &exp, int maxExp);

/// <summary>
/// 現在のステータスを確認
/// </summary>
/// <param name="playerLv"></param>
/// <param name="playerExp"></param>
void StatusOpen(int playerLv, int playerExp);

/// <summary>
/// 入力チェック
/// </summary>
/// <param name="min"></param>
/// <param name="max"></param>
/// <returns></returns>
int InputCheck(int min, int max);

/// <summary>
/// じゃんけんの勝敗
/// </summary>
/// <param name="player"></param>
/// <param name="cpu"></param>
Result Judgement(int player, int cpu);

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

	const int HAND_NUM{ 3 };
}
