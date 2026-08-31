#include <iostream>
#include <string>
#include "Bank.h"
using namespace std;

//コンストラクタの実装
BankAccount::BankAccount(const string& holder, double initialBalance)
    : accountHolder(holder), balance(initialBalance) {}

//現在の残高を返す関数
double BankAccount::getBalance() const {
    return balance;
}

//預け入れ処理
void BankAccount::deposit(double amount) {
    if (amount > 0) {
        balance += amount;
        cout << "Deposited: " << amount << "\n";
    }
    else {
        //無効な入金エラーメッセージ
        cout << "Invalid deposit amount.\n";
    }
}

//引き出し処理
void BankAccount::withdraw(double amount) {
    if (amount > 0 && amount <= balance)
    {
        balance -= amount;
        cout << "Withdrawn: " << amount << "\n";
    }
    else
    {
        //出金のエラーメッセージ
        cout << "Invalid withdraw amount or insufficient funds.\n";
    }
}

//口座情報を返す関数
void BankAccount::displayAccountInfo() const
{
    cout << "Account Holder: " << accountHolder << "\n"
        << "Current Balance: " << balance << "\n";
}