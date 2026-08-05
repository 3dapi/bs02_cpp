#include <iostream>
#include <mutex>
#include <thread>

std::mutex mutex;
int result = 0;
bool ready = false;

void Produce()
{
    std::lock_guard lock{mutex};
    result = 100;
    ready = true;
}

int Consume()
{
    std::lock_guard lock{mutex};

    if (ready)
    {
        return result;
    }

    return 0;
}

int main()
{
    std::jthread producer{Produce};
    producer.join();

    std::cout << Consume() << '\n';
}
