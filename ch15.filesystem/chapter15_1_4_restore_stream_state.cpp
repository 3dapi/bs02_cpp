#include <iomanip>
#include <iostream>

void PrintHex(std::ostream& output, int value)
{
    const auto oldFlags = output.flags();
    const auto oldFill = output.fill();

    output << std::showbase
           << std::hex
           << std::setfill('0')
           << value;

    output.flags(oldFlags);
    output.fill(oldFill);
}

int main()
{
    PrintHex(std::cout, 255);
    std::cout << '\n' << 255 << '\n';
}
