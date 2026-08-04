#include <iostream>
#include <optional>
#include <string>

int main()
{
    std::optional<std::string> message{
        std::in_place,
        5,
        '*'
    };

    std::cout << *message << '\n';

    message.emplace(4, 'A');
    std::cout << *message << '\n';

    message.emplace("updated");
    std::cout << *message << '\n';
}
