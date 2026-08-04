#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int main()
{
    std::vector<std::string> source{"Sword", "Shield", "Potion"};
    std::vector<std::string> destination(source.size());

    std::move(
        source.begin(),
        source.end(),
        destination.begin());

    for (const std::string& value : destination)
    {
        std::cout << value << ' ';
    }
}
