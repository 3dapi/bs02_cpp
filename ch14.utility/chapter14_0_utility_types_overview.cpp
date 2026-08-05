#include <iostream>
#include <optional>
#include <string>
#include <utility>
#include <variant>

int main()
{
    std::pair<int, std::string> item{1001, "Potion"};
    std::optional<int> score = 100;
    std::variant<int, std::string> value = std::string{"ready"};

    std::cout << item.first << ' ' << item.second << '\n';
    std::cout << score.value_or(0) << '\n';
    std::cout << std::get<std::string>(value) << '\n';
}
