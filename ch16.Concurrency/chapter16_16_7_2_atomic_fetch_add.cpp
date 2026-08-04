#include <atomic>
#include <iostream>

int main()
{
    std::atomic<int> count = 0;

    const int oldValue = count.fetch_add(1);
    const int newValue = ++count;

    std::cout << oldValue << ' '
              << newValue << ' '
              << count.load() << '\n';
}
