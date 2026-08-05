#include <iostream>
#include <string>
#include <utility>

int main()
{
    std::string source = "Player";
    std::string copied(source);
    std::string moved(std::move(source));

    std::cout << copied << '\n';
    std::cout << moved << '\n';
}
