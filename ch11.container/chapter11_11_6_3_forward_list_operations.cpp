#include <forward_list>
#include <iostream>

int main()
{
    std::forward_list<int> values{20, 30};

    values.push_front(10);
    values.insert_after(values.begin(), 15);
    values.insert_after(values.before_begin(), 5);
    values.erase_after(values.before_begin());

    for (int value : values)
    {
        std::cout << value << ' ';
    }

    std::cout << '\n';
}
