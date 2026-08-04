#include <concepts>
#include <functional>
#include <iostream>
#include <utility>

template <typename Function, typename... Args>
requires std::invocable<Function, Args...>
decltype(auto) Invoke(Function&& function, Args&&... args)
{
    return std::invoke(
        std::forward<Function>(function),
        std::forward<Args>(args)...);
}

int Add(int left, int right)
{
    return left + right;
}

int main()
{
    std::cout << Invoke(Add, 10, 20) << '\n';
}
