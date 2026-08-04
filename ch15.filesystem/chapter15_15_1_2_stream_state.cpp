#include <iostream>
#include <sstream>

int main()
{
    std::istringstream input{"abc"};
    int value = 0;

    if (input >> value)
    {
        std::cout << "Input: " << value << '\n';
    }
    else
    {
        std::cout << std::boolalpha
                  << "fail=" << input.fail() << '\n'
                  << "bad=" << input.bad() << '\n'
                  << "eof=" << input.eof() << '\n';
    }
}
