#include <iostream>
#include <mutex>

class Account
{
public:
    explicit Account(int balance)
        : balance(balance)
    {
    }

    int GetBalance() const
    {
        std::lock_guard lock{mutex};
        return balance;
    }

    friend void Transfer(Account& from, Account& to, int amount);

private:
    mutable std::mutex mutex;
    int balance = 0;
};

void Transfer(Account& from, Account& to, int amount)
{
    if (&from == &to)
    {
        return;
    }

    std::scoped_lock lock{from.mutex, to.mutex};

    if (from.balance < amount)
    {
        return;
    }

    from.balance -= amount;
    to.balance += amount;
}

int main()
{
    Account first{100};
    Account second{50};

    Transfer(first, second, 30);

    std::cout << first.GetBalance() << ' '
              << second.GetBalance() << '\n';
}
