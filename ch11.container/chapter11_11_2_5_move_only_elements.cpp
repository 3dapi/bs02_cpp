#include <iostream>
#include <memory>
#include <vector>

int main()
{
    std::vector<std::unique_ptr<int>> values;
    values.push_back(std::make_unique<int>(10));
    values.push_back(std::make_unique<int>(20));

    std::cout << *values.front() << ' '
              << *values.back() << '\n';
}
