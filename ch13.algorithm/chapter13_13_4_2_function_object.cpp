#include <iostream>
#include <string>

class Printer
{
public:
    void operator()(int value) const
    {
        std::cout << "int: " << value << '\n';
    }

    void operator()(const std::string& value) const
    {
        std::cout << "string: " << value << '\n';
    }
};

int main()
{
    Printer printer;
    printer(10);
    printer(std::string("Knight"));
}
