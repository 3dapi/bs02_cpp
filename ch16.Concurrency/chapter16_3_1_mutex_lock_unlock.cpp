#include <iostream>
#include <mutex>
#include <thread>

int value = 0;
std::mutex mutex;

void SetValue(int newValue)
{
    mutex.lock();
    value = newValue;
    mutex.unlock();
}

int main()
{
    std::jthread worker{SetValue, 42};
    worker.join();

    std::cout << value << '\n';
}
