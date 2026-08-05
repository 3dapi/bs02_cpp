#include <iostream>
#include <mutex>
#include <thread>

class Counter
{
public:
    void Increase()
    {
        std::lock_guard lock{mutex};
        ++value;
    }

    int Get() const
    {
        std::lock_guard lock{mutex};
        return value;
    }

private:
    mutable std::mutex mutex;
    int value = 0;
};

int main()
{
    Counter counter;

    std::jthread first{[&] { counter.Increase(); }};
    std::jthread second{[&] { counter.Increase(); }};

    first.join();
    second.join();

    std::cout << counter.Get() << '\n';
}
