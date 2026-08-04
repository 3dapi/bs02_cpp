#include <iostream>
#include <map>
#include <string>
#include <unordered_map>

int main()
{
    std::map<int, std::string> ordered
    {
        {30, "C"},
        {10, "A"},
        {20, "B"}
    };

    std::unordered_map<int, std::string> unordered
    {
        {30, "C"},
        {10, "A"},
        {20, "B"}
    };

    for (const auto& [key, value] : ordered)
    {
        std::cout << key << value << ' ';
    }
    std::cout << '\n';

    std::cout << unordered.size() << '\n';
}
