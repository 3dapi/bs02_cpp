#include <future>
#include <iostream>

int Calculate()
{
    return 40 + 2;
}

int main()
{
    std::future<int> result = std::async(
        std::launch::async,
        Calculate);

    std::cout << result.get() << '\n';
}
