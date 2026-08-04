#include <iostream>
#include <limits>
#include <sstream>

int ReadInteger(std::istream& input)
{
    int value = 0;

    while (!(input >> value))
    {
        input.clear();
        input.ignore(
            std::numeric_limits<std::streamsize>::max(),
            '\n');
    }

    return value;
}

int main()
{
    std::istringstream input{"wrong input\n42\n"};
    std::cout << ReadInteger(input) << '\n';
}
