#include <iostream>
#include <iterator>
#include <list>
#include <vector>

int main()
{
    std::vector<int> vectorValues{10, 20, 30, 40};
    std::list<int> listValues{10, 20, 30, 40};

    std::cout << std::distance(vectorValues.begin(), vectorValues.end()) << '\n';
    std::cout << std::distance(listValues.begin(), listValues.end()) << '\n';
}
