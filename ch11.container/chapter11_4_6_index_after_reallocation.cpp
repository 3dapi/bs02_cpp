#include <iostream>
#include <vector>

int main()
{
    std::vector<int> values{10, 20, 30};
    std::size_t index = 1;

    values.push_back(40);

    int& value = values[index];
    std::cout << value << '\n';
}
