#include <iostream>
#include <string>

int main()
{
    const std::string& reference = std::string("temporary");
    std::cout << reference << '\n';
}
