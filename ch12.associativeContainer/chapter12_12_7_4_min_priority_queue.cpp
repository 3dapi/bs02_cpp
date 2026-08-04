#include <functional>
#include <iostream>
#include <queue>
#include <vector>

int main()
{
    std::priority_queue<
        int,
        std::vector<int>,
        std::greater<int>> minQueue;

    minQueue.push(30);
    minQueue.push(10);
    minQueue.push(20);

    std::cout << minQueue.top() << '\n';
}
