#include <iostream>
#include <string>
#include <string_view>

template <typename Key, typename Value>
struct PairStorage
{
    static constexpr std::string_view Kind()
    {
        return "general";
    }
};

template <typename Value>
struct PairStorage<std::string, Value>
{
    static constexpr std::string_view Kind()
    {
        return "string key";
    }
};

int main()
{
    std::cout << PairStorage<int, double>::Kind() << '\n';
    std::cout << PairStorage<std::string, int>::Kind() << '\n';
}
