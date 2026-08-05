#include <iostream>
#include <sstream>

int main()
{
    std::istringstream input{"10 20 30"};
    int value = 0;

    while (input >> value)
    {
        std::cout << value << '\n';
    }

    if (!input.eof())
    {
        std::cerr << "Invalid data format\n";
    }
}
