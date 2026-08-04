#include <iostream>
#include <string>
#include <tuple>

int main()
{
    std::tuple<int, std::string, int> player{1, "Knight", 100};
    auto monster = std::make_tuple(10, std::string{"Slime"}, 30);

    std::cout << std::get<0>(player) << ' '
              << std::get<1>(player) << ' '
              << std::get<2>(player) << '\n';

    std::cout << std::get<0>(monster) << ' '
              << std::get<1>(monster) << ' '
              << std::get<2>(monster) << '\n';
}
