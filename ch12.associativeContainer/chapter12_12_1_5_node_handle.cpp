#include <iostream>
#include <set>
#include <string>
#include <utility>

int main()
{
    std::set<std::string> names{"Alice", "Bob", "Carol"};
    auto node = names.extract("Bob");

    if (!node.empty())
    {
        node.value() = "Bobby";
        auto result = names.insert(std::move(node));
        std::cout << std::boolalpha << result.inserted << '\n';
    }

    for (const std::string& name : names)
    {
        std::cout << name << ' ';
    }
    std::cout << '\n';
}
