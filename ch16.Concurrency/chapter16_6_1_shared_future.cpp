#include <future>
#include <iostream>

int main()
{
    std::future<int> result = std::async(
        std::launch::async,
        []
        {
            return 100;
        });

    std::shared_future<int> shared = std::move(result);

    std::cout << shared.get() << ' '
              << shared.get() << '\n';
}
