#include <iostream>
#include <string>
#include <utility>

int main()
{
    std::pair<int, std::string> firstItem{1001, "Potion"};
    auto secondItem = std::make_pair(1002, std::string{"Ether"});
    std::pair thirdItem{1003, std::string{"Elixir"}};

    std::cout << firstItem.first << ' ' << firstItem.second << '\n';
    std::cout << secondItem.first << ' ' << secondItem.second << '\n';
    std::cout << thirdItem.first << ' ' << thirdItem.second << '\n';
}
