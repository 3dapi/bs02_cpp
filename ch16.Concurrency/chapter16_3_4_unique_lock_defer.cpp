#include <iostream>
#include <mutex>

int main()
{
    std::mutex mutex;
    int sharedValue = 0;

    std::unique_lock lock{mutex, std::defer_lock};
    const int preparedValue = 42;

    lock.lock();
    sharedValue = preparedValue;

    std::cout << std::boolalpha
              << lock.owns_lock() << ' '
              << sharedValue << '\n';
}
