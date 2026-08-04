#include <future>
#include <iostream>

int main()
{
    std::future<int> result;

    {
        std::promise<int> promise;
        result = promise.get_future();
    }

    try
    {
        std::cout << result.get() << '\n';
    }
    catch (const std::future_error& error)
    {
        std::cout << (error.code() == std::make_error_code(
            std::future_errc::broken_promise)) << '\n';
    }
}
