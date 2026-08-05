#include <iostream>
#include <stdexcept>
#include <string>

int main()
{
    std::string text = "12A";
    std::size_t parsed = 0;

    try
    {
        int value = std::stoi(text, &parsed);
        std::cout << value << '\n';

        if (parsed != text.size())
        {
            std::cout << "remaining characters\n";
        }
    }
    catch (const std::invalid_argument&)
    {
        std::cout << "invalid number\n";
    }
    catch (const std::out_of_range&)
    {
        std::cout << "number out of range\n";
    }
}
