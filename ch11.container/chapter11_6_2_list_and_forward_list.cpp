#include <forward_list>
#include <iostream>
#include <list>

int main()
{
    std::list<int> bidirectional{10, 20, 30};
    auto iterator = bidirectional.end();
    --iterator;

    std::forward_list<int> forward{40, 50, 60};

    std::cout << *iterator << ' ' << forward.front() << '\n';
}
