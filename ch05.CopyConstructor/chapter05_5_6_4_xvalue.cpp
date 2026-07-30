#include <iostream>
#include <string>
#include <utility>

int main()
{
    std::string source = "Player";
    std::string target(std::move(source));

    std::cout << target << '\n';
    std::cout << "source size: " << source.size() << '\n';
}
