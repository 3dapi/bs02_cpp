#include <format>
#include <iostream>

int main()
{
    int width = 10;
    int precision = 3;

    auto text = std::format(
        "{0:{1}.{2}f}",
        12.34567,
        width,
        precision);

    std::cout << text << '\n';
}
