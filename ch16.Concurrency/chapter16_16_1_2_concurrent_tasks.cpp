#include <chrono>
#include <iostream>
#include <thread>

using namespace std::chrono_literals;

void RunTask(int& result, int value)
{
    std::this_thread::sleep_for(10ms);
    result = value;
}

int main()
{
    int first = 0;
    int second = 0;

    std::jthread firstWorker{RunTask, std::ref(first), 10};
    std::jthread secondWorker{RunTask, std::ref(second), 20};

    firstWorker.join();
    secondWorker.join();

    std::cout << first + second << '\n';
}
