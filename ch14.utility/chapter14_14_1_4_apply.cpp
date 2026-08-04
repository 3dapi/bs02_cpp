#include <functional>
#include <iostream>
#include <string>
#include <tuple>

int Add(int left, int right)
{
    return left + right;
}

int main()
{
    std::tuple<int, int> arguments{10, 20};
    int result = std::apply(Add, arguments);
    std::cout << result << '\n';

    auto player = std::make_tuple(std::string{"Knight"}, 5, 100);

    std::apply(
        [](const std::string& name, int level, int hp)
        {
            std::cout << name << ' ' << level << ' ' << hp << '\n';
        },
        player);
}
