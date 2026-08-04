#include <algorithm>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

int main()
{
    std::vector<std::string> names{"Knight", "Mage"};
    std::sort(names.begin(), names.end());

    auto score = std::make_unique<int>(100);
    std::cout << names.front() << ' ' << *score << '\n';
}
