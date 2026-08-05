#include <iostream>
#include <list>

int main()
{
    std::list<int> values{10, 20, 30};

    auto iterator = values.end();
    --iterator;

    std::cout << *iterator << '\n';
}
