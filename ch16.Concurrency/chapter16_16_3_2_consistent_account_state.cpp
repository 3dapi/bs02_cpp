#include <iostream>
#include <mutex>
#include <utility>

class Account
{
public:
    void Deposit(int amount)
    {
        std::lock_guard lock{mutex};
        balance += amount;
        ++transactionCount;
    }

    std::pair<int, int> GetState() const
    {
        std::lock_guard lock{mutex};
        return {balance, transactionCount};
    }

private:
    mutable std::mutex mutex;
    int balance = 0;
    int transactionCount = 0;
};

int main()
{
    Account account;
    account.Deposit(100);

    auto [balance, transactionCount] = account.GetState();
    std::cout << balance << ' ' << transactionCount << '\n';
}
