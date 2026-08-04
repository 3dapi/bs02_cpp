#include <iostream>
#include <thread>

void PrintMessage()
{
    std::cout << "worker thread\n";
}

int main()
{
    std::thread worker{PrintMessage};
    worker.join();
}
