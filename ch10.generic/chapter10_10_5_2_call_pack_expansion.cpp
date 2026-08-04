#include <iostream>

template <typename Function, typename... Args>
auto Call(Function function, const Args&... args)
{
    return function(args...);
}

int AddThree(int first, int second, int third)
{
    return first + second + third;
}

int main()
{
    int result = Call(AddThree, 10, 20, 30);
    std::cout << result << '\n';
}
