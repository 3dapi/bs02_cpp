#include <array>
#include <iostream>
#include <string>
#include <vector>

int main()
{
    std::vector<std::string> names;
    names.push_back("Alice");
    names.push_back("Bob");
    names.pop_back();

    std::vector<int> values{10, 40};
    std::array<int, 2> middle{20, 30};

    values.insert(
        values.begin() + 1,
        middle.begin(),
        middle.end());

    values.erase(values.begin());

    for (int value : values)
    {
        std::cout << value << ' ';
    }

    std::cout << names.front() << '\n';
}
