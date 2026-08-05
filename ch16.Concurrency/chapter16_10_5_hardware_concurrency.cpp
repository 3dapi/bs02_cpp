#include <iostream>
#include <thread>

int main()
{
    unsigned int count = std::thread::hardware_concurrency();

    if (count == 0)
    {
        count = 1;
    }

    std::cout << (count >= 1) << '\n';
}
