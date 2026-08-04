#include <iostream>
#include <thread>

thread_local int currentWorkerId = 0;

void Work(int workerId)
{
    currentWorkerId = workerId;

    std::cout << "worker: "
              << currentWorkerId << '\n';
}

int main()
{
    std::thread first(Work, 1);
    first.join();

    std::thread second(Work, 2);
    second.join();

    std::cout << "main worker: "
              << currentWorkerId << '\n';
}
