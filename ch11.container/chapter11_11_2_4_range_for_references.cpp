#include <iostream>
#include <string>
#include <vector>

int main()
{
    std::vector<int> values{1, 2, 3};

    for (int& value : values)
    {
        value += 1;
    }

    std::vector<std::string> names{"Knight", "Mage"};

    for (const std::string& name : names)
    {
        std::cout << name << ' ';
    }

    std::cout << values.front() << '\n';
}
