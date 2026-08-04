#include <iostream>
#include <string>
#include <utility>
#include <vector>

int main()
{
    std::vector<std::string> original{"A", "B", "C"};
    std::vector<std::string> copied = original;

    copied.front() = "Changed";
    std::cout << original.front() << ' ' << copied.front() << '\n';

    std::vector<std::string> moved = std::move(original);
    std::cout << moved.size() << '\n';

    original.clear();
}
