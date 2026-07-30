#include <iostream>
#include <iterator>

int main()
{
    const char text[] = "ABC";
    std::cout << std::size(text) << ' ' << std::size(text) - 1 << '\n';
}
