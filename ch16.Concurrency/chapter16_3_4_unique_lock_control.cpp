#include <iostream>
#include <mutex>

int main()
{
    std::mutex mutex;
    int value = 0;

    std::unique_lock lock{mutex};
    value = 10;
    lock.unlock();

    const int local = value * 2;

    lock.lock();
    value = local;
    lock.unlock();

    std::cout << value << '\n';
}
