#include <chrono>
#include <iostream>
#include <thread>

using namespace std::chrono_literals;

void PrintMessage()
{
    std::this_thread::sleep_for(5ms);
    std::cout << "jthread worker\n";
}

int main()
{
    std::jthread worker{PrintMessage};
}
