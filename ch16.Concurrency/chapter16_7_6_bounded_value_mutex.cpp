#include <iostream>
#include <mutex>

class BoundedValue
{
public:
    bool Add(int amount)
    {
        std::lock_guard lock{mutex};

        if (value + amount > maximum)
        {
            return false;
        }

        value += amount;
        return true;
    }

    int Get() const
    {
        std::lock_guard lock{mutex};
        return value;
    }

private:
    mutable std::mutex mutex;
    int value = 0;
    int maximum = 100;
};

int main()
{
    BoundedValue value;

    std::cout << std::boolalpha
              << value.Add(70) << ' '
              << value.Add(40) << ' '
              << value.Get() << '\n';
}
