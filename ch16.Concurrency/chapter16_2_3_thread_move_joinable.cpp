#include <iostream>
#include <thread>

void RunTask()
{
}

int main()
{
    std::thread first{RunTask};
    std::thread second{std::move(first)};

    std::cout << std::boolalpha
              << first.joinable() << ' '
              << second.joinable() << '\n';

    second.join();
}
