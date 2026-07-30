#include <iostream>

class BankAccount
{
public:
    void Deposit(int amount)
    {
        if (amount > 0)
        {
            balance += amount;
        }
    }

    bool Withdraw(int amount)
    {
        if (amount <= 0 || amount > balance)
        {
            return false;
        }

        balance -= amount;
        return true;
    }

    int GetBalance() const
    {
        return balance;
    }

private:
    int balance = 0;
};

int main()
{
    BankAccount account;

    account.Deposit(10000);
    account.Withdraw(3000);

    std::cout << account.GetBalance() << '\n';
    // account.balance = -10000; // 오류
}
