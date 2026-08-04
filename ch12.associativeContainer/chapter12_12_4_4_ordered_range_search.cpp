#include <iostream>
#include <map>
#include <string>

int main()
{
    std::map<int, std::string> players
    {
        {900, "A"},
        {1000, "B"},
        {1500, "C"},
        {1999, "D"},
        {2000, "E"}
    };

    auto first = players.lower_bound(1000);
    auto last = players.upper_bound(1999);

    for (auto iterator = first; iterator != last; ++iterator)
    {
        std::cout << iterator->first << ' ';
    }
    std::cout << '\n';
}
