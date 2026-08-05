#include <iostream>
#include <vector>

int main()
{
    using Container = std::vector<int>;

    Container::value_type value = 10;
    Container values{value, 20, 30};
    Container::size_type count = values.size();
    Container::iterator iterator = values.begin();
    Container::const_iterator constIterator = values.cbegin();

    if (!values.empty())
    {
        std::cout << count << ' '
                  << *iterator << ' '
                  << *constIterator << '\n';
    }
}
