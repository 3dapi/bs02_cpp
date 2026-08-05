#include <iostream>
#include <list>
#include <string>
#include <vector>

int main()
{
    std::vector<int> scores{80, 90, 100};
    std::list<std::string> names{"Alice", "Bob"};

    scores.front() = 85;
    names.front() = "Knight";

    std::cout << scores.front() << ' ' << names.front() << '\n';
}
