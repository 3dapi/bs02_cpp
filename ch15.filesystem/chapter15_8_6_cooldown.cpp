#include <chrono>
#include <iostream>

class Cooldown
{
public:
    explicit Cooldown(std::chrono::milliseconds interval)
        : interval(interval),
          readyTime(std::chrono::steady_clock::time_point::min())
    {
    }

    bool TryActivate()
    {
        const auto now = std::chrono::steady_clock::now();

        if (now < readyTime)
        {
            return false;
        }

        readyTime = now + interval;
        return true;
    }

private:
    std::chrono::milliseconds interval;
    std::chrono::steady_clock::time_point readyTime;
};

int main()
{
    Cooldown cooldown{std::chrono::seconds{1}};
    std::cout << std::boolalpha
              << cooldown.TryActivate() << '\n'
              << cooldown.TryActivate() << '\n';
}
