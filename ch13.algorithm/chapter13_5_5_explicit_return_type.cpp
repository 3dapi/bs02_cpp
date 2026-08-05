#include <iostream>

int main()
{
    auto convert = [](bool useInteger) -> double
    {
        if (useInteger)
        {
            return 10;
        }

        return 3.5;
    };

    std::cout << convert(true) << '\n';
    std::cout << convert(false) << '\n';
}
