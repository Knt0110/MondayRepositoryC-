#include <iostream>
#include <string>
#include "Bank.h"
using namespace std;

int main() {

    //accountという名前でオブジェクト作成
    //口座名義者「Alice」、初期金額「5000」で設定
    BankAccount account("Alice", 5000.0);

    //初期状態の口座情報を表示
    account.displayAccountInfo();

    account.deposit(1000.0);    //1000円入金
    account.withdraw(2000.0);   //2000円出金
    account.withdraw(5000.0); // 残高不足で失敗

    //上記操作後の口座情報を表示
    account.displayAccountInfo();

    return 0;
}