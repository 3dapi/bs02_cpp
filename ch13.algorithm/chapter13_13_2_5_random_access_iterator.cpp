#include <iostream>
#include <vector>

int main()
{
    std::vector<int> values{10, 20, 30, 40};

    auto iterator = values.begin();
    iterator += 2;

    std::cout << *iterator << '\n';
    std::cout << iterator[1] << '\n';
}
