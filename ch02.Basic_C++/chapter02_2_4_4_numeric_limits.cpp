#include <iostream>
#include <limits>

int main()
{
    std::cout << std::numeric_limits<int>::min() << '\n' << std::numeric_limits<int>::max() << '\n' << std::numeric_limits<double>::lowest() << '\n';
}
