#include <iostream>
#include <queue>

int main()
{
    std::priority_queue<int> values;

    values.push(30);
    values.push(10);
    values.push(50);
    values.push(20);

    std::cout << values.top() << '\n';
    values.pop();
    std::cout << values.top() << '\n';
}
