#include <iostream>
#include <mutex>

std::mutex firstMutex;
std::mutex secondMutex;
int value = 0;

void Update()
{
    std::lock_guard firstLock{firstMutex};
    std::lock_guard secondLock{secondMutex};
    ++value;
}

int main()
{
    Update();
    Update();
    std::cout << value << '\n';
}
