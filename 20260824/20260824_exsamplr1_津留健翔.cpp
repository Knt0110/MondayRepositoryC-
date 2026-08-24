#include <iostream>
using namespace std;

int main(void)
{
    //変数宣言＆初期化
    int a = 0;
    int* p = &a;    //*pにaのアドレスを持たせる

    //aを表示
    cout << "aの初期値: " << a << endl;

    //*pを通して、aを書き換える
    *p = 10;

    //変更後のaを表示
    cout << "aの変更後の値: " << a << endl;

    return 0;
}