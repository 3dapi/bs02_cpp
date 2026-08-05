#include <format>
#include <iostream>

int main()
{
    std::cout << std::format("{:08}", 42) << '\n';
    std::cout << std::format("{:*^10}", "title") << '\n';
    std::cout << std::format("{:8.2f}", 12.3456) << '\n';
    std::cout << std::format("{:#x}", 255) << '\n';
}
