#include <iostream>
#include <thread>

int main()
{
    std::thread worker{
        []
        {
            std::cout << "lambda thread\n";
        }};

    worker.join();
}
