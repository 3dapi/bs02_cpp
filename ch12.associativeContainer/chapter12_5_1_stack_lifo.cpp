#include <iostream>
#include <stack>

int main()
{
    std::stack<int> values;

    values.push(10);
    values.push(20);
    values.push(30);

    std::cout << values.top() << '\n';
    values.pop();
    std::cout << values.top() << '\n';

    if (!values.empty())
    {
        int value = values.top();
        values.pop();
        std::cout << value << '\n';
    }
}
