#include <iostream>
#include <sstream>

int main()
{
    std::istringstream input{"abc"};
    int value = 0;

    input >> value;

    input.clear();
    input.str("100");
    input >> value;

    std::ostringstream output;
    output << "first";
    output.str("");
    output.clear();
    output << "second";

    std::cout << value << ' ' << output.str() << '\n';
}
