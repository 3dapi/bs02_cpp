#include <iostream>
#include <memory>

bool Process(bool valid)
{
    std::unique_ptr<int[]> values =
        std::make_unique<int[]>(100);

    if (!valid)
    {
        return false;
    }

    values[0] = 100;
    std::cout << values[0] << '\n';

    return true;
}

int main()
{
    std::cout << std::boolalpha;
    std::cout << Process(false) << '\n';
    std::cout << Process(true) << '\n';
}
