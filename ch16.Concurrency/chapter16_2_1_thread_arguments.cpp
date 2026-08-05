#include <iostream>
#include <thread>

void AddRange(int first, int last, int& result)
{
    int total = 0;

    for (int value = first; value <= last; ++value)
    {
        total += value;
    }

    result = total;
}

int main()
{
    int result = 0;
    std::thread worker{AddRange, 1, 5, std::ref(result)};
    worker.join();

    std::cout << result << '\n';
}
