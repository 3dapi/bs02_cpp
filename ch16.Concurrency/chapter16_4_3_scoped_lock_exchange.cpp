#include <iostream>
#include <mutex>
#include <utility>

class Data
{
public:
    explicit Data(int value)
        : value(value)
    {
    }

    int Get() const
    {
        std::lock_guard lock{mutex};
        return value;
    }

    friend void Exchange(Data& left, Data& right);

private:
    mutable std::mutex mutex;
    int value = 0;
};

void Exchange(Data& left, Data& right)
{
    if (&left == &right)
    {
        return;
    }

    std::scoped_lock lock{left.mutex, right.mutex};
    std::swap(left.value, right.value);
}

int main()
{
    Data first{10};
    Data second{20};

    Exchange(first, second);
    std::cout << first.Get() << ' ' << second.Get() << '\n';
}
