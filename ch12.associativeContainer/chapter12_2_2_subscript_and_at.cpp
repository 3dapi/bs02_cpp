#include <iostream>
#include <map>
#include <stdexcept>
#include <string>

int main()
{
    std::map<std::string, int> counts;

    int potionCount = counts["Potion"];
    std::cout << potionCount << ' ' << counts.size() << '\n';

    if (counts.contains("Potion"))
    {
        std::cout << counts.at("Potion") << '\n';
    }

    try
    {
        int count = counts.at("Ether");
        std::cout << count << '\n';
    }
    catch (const std::out_of_range&)
    {
        std::cout << "key not found\n";
    }
}
