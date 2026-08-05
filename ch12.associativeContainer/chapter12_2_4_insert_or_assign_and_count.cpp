#include <iostream>
#include <map>
#include <string>
#include <vector>

int main()
{
    std::map<int, std::string> names;

    names.insert_or_assign(1001, "Potion");
    names.insert_or_assign(1001, "High Potion");

    std::vector<std::string> itemNames
    {
        "Potion", "Ether", "Potion"
    };
    std::map<std::string, int> counts;

    for (const std::string& name : itemNames)
    {
        ++counts[name];
    }

    std::cout << names.at(1001) << '\n';
    std::cout << counts.at("Potion") << '\n';
}
