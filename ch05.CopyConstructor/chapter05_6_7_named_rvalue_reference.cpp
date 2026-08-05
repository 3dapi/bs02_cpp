#include <iostream>
#include <string>
#include <utility>

void Process(const std::string& value)
{
    std::cout << "copy path: " << value << '\n';
}

void Process(std::string&& value)
{
    std::cout << "move path: " << value << '\n';
}

int main()
{
    std::string&& reference = std::string("Player");

    Process(reference);
    Process(std::move(reference));
}
