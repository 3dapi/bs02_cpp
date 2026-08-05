#include <compare>
#include <iostream>

struct Version
{
    int major = 0;
    int minor = 0;
    int patch = 0;

    auto operator<=>(const Version&) const = default;
};

int main()
{
    Version first{1, 4, 2};
    Version second{1, 5, 0};
    Version copy{1, 4, 2};

    std::cout << std::boolalpha;
    std::cout << (first < second) << '\n';
    std::cout << (first == copy) << '\n';
}
