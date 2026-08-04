#include <functional>
#include <iostream>
#include <thread>

void SetValue(int& target, int value)
{
    target = value;
}

int main()
{
    int number = 0;

    std::thread worker{SetValue, std::ref(number), 100};
    worker.join();

    std::cout << number << '\n';
}
