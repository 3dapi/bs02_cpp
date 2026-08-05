#include <iostream>
#include <string>
#include <utility>

int main()
{
    std::pair<int, std::string> item{1001, "Potion"};

    auto [idCopy, nameCopy] = item;
    nameCopy = "Ether";

    auto& [idReference, nameReference] = item;
    nameReference = "Elixir";

    const auto& [idView, nameView] = item;

    std::cout << idCopy << ' ' << nameCopy << '\n';
    std::cout << idReference << ' ' << nameReference << '\n';
    std::cout << idView << ' ' << nameView << '\n';
}
