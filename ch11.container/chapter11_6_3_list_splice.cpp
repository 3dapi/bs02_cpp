#include <iostream>
#include <list>

int main()
{
    std::list<int> first{10, 20};
    std::list<int> second{30, 40};

    auto moved = second.begin();
    int* address = &*moved;

    first.splice(first.end(), second);

    std::cout << first.size() << ' '
              << second.size() << ' '
              << std::boolalpha
              << (address == &*moved) << '\n';
}
