#include <functional>
#include <iostream>
#include <string>
#include <unordered_set>

int main()
{
    std::size_t hashValue = std::hash<std::string>{}("Potion");
    std::unordered_set<std::string> names{"Alice", "Bob", "Carol"};

    std::cout << hashValue << '\n';
    std::cout << names.bucket_count() << '\n';
    std::cout << names.bucket("Alice") << '\n';
}
