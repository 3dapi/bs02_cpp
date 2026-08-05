#include <future>
#include <iostream>
#include <stdexcept>
#include <thread>

void Produce(std::promise<int> promise)
{
    try
    {
        throw std::runtime_error{"calculation failed"};
    }
    catch (...)
    {
        promise.set_exception(std::current_exception());
    }
}

int main()
{
    std::promise<int> promise;
    std::future<int> result = promise.get_future();
    std::jthread worker{Produce, std::move(promise)};

    try
    {
        std::cout << result.get() << '\n';
    }
    catch (const std::exception& exception)
    {
        std::cout << exception.what() << '\n';
    }
}
