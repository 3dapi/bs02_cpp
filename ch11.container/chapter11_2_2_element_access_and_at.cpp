#include <iostream>
#include <stdexcept>
#include <vector>

int main()
{
    std::vector<int> values{10, 20, 30};
    std::cout << values[1] << '\n';

    try
    {
        std::cout << values.at(10) << '\n';
    }
    catch (const std::out_of_range& error)
    {
        std::cout << error.what() << '\n';
    }
}
