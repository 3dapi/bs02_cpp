#include <iostream>
#include <set>
#include <string>

int main()
{
    std::set<std::string> names;

    names.insert("Alice");
    names.emplace("Bob");

    auto position = names.find("Alice");

    if (position != names.end())
    {
        std::cout << *position << '\n';
    }

    if (names.contains("Bob"))
    {
        std::cout << "found\n";
    }

    std::cout << names.count("Carol") << '\n';
}
