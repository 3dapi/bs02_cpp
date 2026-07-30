#include <iostream>
#include <limits>

int main()
{
    std::cout << std::numeric_limits<float>::epsilon() << '\n' << std::numeric_limits<double>::epsilon() << '\n';
}
