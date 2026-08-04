#include <atomic>
#include <iostream>
#include <thread>

int data = 0;
std::atomic<bool> ready = false;

void Produce()
{
    data = 100;
    ready.store(true, std::memory_order_release);
}

void Consume(int& result)
{
    while (!ready.load(std::memory_order_acquire))
    {
    }

    result = data;
}

int main()
{
    int result = 0;

    std::jthread consumer{Consume, std::ref(result)};
    std::jthread producer{Produce};

    producer.join();
    consumer.join();

    std::cout << result << '\n';
}
