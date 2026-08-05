#include <deque>
#include <iostream>
#include <queue>

int main()
{
    std::priority_queue<int, std::deque<int>> values;
    values.push(10);
    values.push(30);
    values.push(20);

    std::cout << values.top() << '\n';
}
