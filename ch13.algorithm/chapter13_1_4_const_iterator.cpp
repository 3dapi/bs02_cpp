#include <iostream>
#include <vector>

int main()
{
    std::vector<int> values{10, 20, 30};

    std::vector<int>::const_iterator readOnly = values.cbegin();
    ++readOnly;
    std::cout << *readOnly << '\n';

    std::vector<int>::iterator const fixedPosition = values.begin();
    *fixedPosition = 100;
    std::cout << values.front() << '\n';
}
