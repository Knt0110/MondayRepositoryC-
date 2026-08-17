#include <iostream>
#include <cstdlib>
#include <ctime>
#include "20260817_Prac1_header.h"

using namespace std;

// 定数
const int PITING_MIN = 0;
const int PITING_MAX = 3;
const int PROBABILITY = 4;
const int STRIKE_COUNT = 3;
const int BALL_COUNT = 4;
const int OUT_COUNT = 3;
const int HIT_COUNT = 4;

int main(void)
{
    //変数宣言&初期化
    int ply, emy;
    int prod;
    int Strike = 0;
    int Ball = 0;
    int Out = 0;
    int Hit = 0;

    //乱数生成の初期化
    srand((unsigned int)time(NULL));

    //ゲーム開始のメッセージ表示
    cout << "野球盤ゲームスタートです" << endl;
    cout << "プレイヤーはピッチャーとなり、この回を守り切ってください" << endl;

    while (Out < OUT_COUNT && Hit < HIT_COUNT)
    {
        //選択肢の表示
        cout << "投げる球を選んでください" << endl;
        cout << "0:ストレート "
            << "1:カーブ "
            << "2:スライダー "
            << "3:シンカー"
            << endl;

        //入力チェック
        while (true)
        {
            cin >> ply;

            if (PITING_MIN > ply || PITING_MAX < ply)
            {
                cout << "入力に誤りがあります。"
                    << "再度入力してください。"
                    << endl;
            }
            else
            {
                break;
            }
        }

        //プレイヤーの投げた球を表示
        PitingType(ply);

        //NPCの行動生成
        emy = rand() % PROBABILITY;

        //打球や判定の成否を決める乱数
        prod = rand() % PROBABILITY;

        //投球結果の判定
        //プレイヤーと敵の選択の不一致
        if (ply != emy)
        {
            if (prod == 0)
            {
                cout << "ボール！" << endl;
                Ball++;
            }
            else
            {
                cout << "ストライク！！" << endl;
                Strike++;
            }
        }
        //プレイヤーと敵の選択の一致
        else
        {
            Strike = 0;
            Ball = 0;

            if (prod == 1)
            {
                cout << "OUT!!!" << endl;
                Out++;
            }
            else
            {
                cout << "HIT!!" << endl;
                Hit++;
            }
        }

        // 3ストライク / 4ボールの精算処理
        if (Strike >= STRIKE_COUNT || Ball >= BALL_COUNT)
        {
            if (Strike >= STRIKE_COUNT)
            {
                Out++;
            }
            else
            {
                Hit++;
            }

            //打者が変わるので、リセット
            Strike = 0;
            Ball = 0;
        }

        //現在のカウント・状況を表示
        cout << "B:" << Ball << endl;
        cout << "S:" << Strike << endl;
        cout << "O:" << Out << endl;
        cout << "Runner:" << Hit << endl;

    }

    //勝敗の表示
    Result(Out);

    return 0;
}