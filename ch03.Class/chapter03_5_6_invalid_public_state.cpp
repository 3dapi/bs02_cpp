#include <iostream>

struct AccountData
{
    int balance;
};

int main()
{
    AccountData account;

    account.balance = -10000;

    std::cout << account.balance << '\n';
}
