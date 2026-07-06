#pragma once

/// <summary>
/// 回復関数
/// </summary>
/// <param name="playerHp"></param>
/// <param name="heal"></param>
void Heal(int& playerHp, int heal);

/// <summary>
/// HP表示関数
/// </summary>
/// <param name="playerHp"></param>
void ScreenHp(int& playerHp);

/// <summary>
/// 入力チェック
/// </summary>
/// <param name="select"></param>
/// <param name="min"></param>
/// <param name="max"></param>
int InputCheck(int min, int max);

/// <summary>
/// Run関数
/// </summary>
/// <param name="min"></param>
void Run(int min);

//定数宣言
namespace Config
{
	//プレイヤーの初期HP
	const int START_HP{ 100 };
	//回復量
	const int HEAL{ 20 };
	//選択肢の最低値
	const int SELECT_MIN{ 1 };
	//選択肢の最大値
	const int SELECT_MAX{ 2 };
}