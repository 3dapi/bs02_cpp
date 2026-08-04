#include <iostream>
#include <mutex>

int main()
{
    std::mutex firstMutex;
    std::mutex secondMutex;

    std::unique_lock firstLock{firstMutex, std::defer_lock};
    std::unique_lock secondLock{secondMutex, std::defer_lock};

    std::lock(firstLock, secondLock);

    std::cout << std::boolalpha
              << firstLock.owns_lock() << ' '
              << secondLock.owns_lock() << '\n';
}
