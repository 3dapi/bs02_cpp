#include <chrono>
#include <iostream>

using Seconds = std::chrono::duration<double>;

Seconds accumulator{0.0};
constexpr Seconds fixedStep{1.0 / 60.0};
int updateCount = 0;

void FixedUpdate(Seconds deltaTime)
{
    (void)deltaTime;
    ++updateCount;
}

void Tick(Seconds frameTime)
{
    accumulator += frameTime;

    while (accumulator >= fixedStep)
    {
        FixedUpdate(fixedStep);
        accumulator -= fixedStep;
    }
}

int main()
{
    Tick(Seconds{0.05});
    std::cout << updateCount << '\n';
}
