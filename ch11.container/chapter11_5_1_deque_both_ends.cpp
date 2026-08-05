#include <deque>
#include <iostream>

int main()
{
    std::deque<int> values;

    values.push_back(20);
    values.push_front(10);
    values.push_back(30);

    values.pop_front();

    for (int value : values)
    {
        std::cout << value << ' ';
    }

    std::cout << '\n';
}
