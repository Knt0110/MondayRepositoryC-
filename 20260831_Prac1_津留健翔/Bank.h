#pragma once
#include <string>
using namespace std;

//銀行口座アカウントのクラス
class BankAccount
{
private:
    std::string accountHolder; // 口座名義人
    double balance;            // 残高

public:

    //口座名義者と初期残高の設定
    BankAccount(const std::string& holder, double initialBalance);

    //現在の残高を取得する関数
    double getBalance() const;

    //預け入れの関数
    void deposit(double amount);

    //引き出しの関数
    void withdraw(double amount);

    //口座情報を取得する関数
    void displayAccountInfo() const;
};