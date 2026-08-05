#include <iostream>
#include <set>

int main()
{
    std::set<int> ids;

    auto [position, inserted] = ids.insert(1001);

    if (inserted)
    {
        std::cout << "inserted: " << *position << '\n';
    }

    auto [samePosition, insertedAgain] = ids.insert(1001);
    std::cout << *samePosition << ' ' << std::boolalpha
              << insertedAgain << '\n';
}
