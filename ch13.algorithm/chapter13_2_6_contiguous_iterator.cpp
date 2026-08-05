#include <iostream>
#include <memory>
#include <vector>

int main()
{
    std::vector<int> values{10, 20, 30};

    auto iterator = values.begin();
    int* pointer = std::to_address(iterator);

    std::cout << pointer[1] << '\n';
}
