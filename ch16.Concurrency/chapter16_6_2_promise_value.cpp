#include <future>
#include <iostream>
#include <thread>

void Produce(std::promise<int> promise)
{
    promise.set_value(100);
}

int main()
{
    std::promise<int> promise;
    std::future<int> result = promise.get_future();

    std::jthread worker{Produce, std::move(promise)};

    std::cout << result.get() << '\n';
}
