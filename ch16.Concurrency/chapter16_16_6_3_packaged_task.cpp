#include <future>
#include <iostream>
#include <thread>

int Add(int left, int right)
{
    return left + right;
}

int main()
{
    std::packaged_task<int(int, int)> task{Add};
    std::future<int> result = task.get_future();

    std::jthread worker{std::move(task), 10, 20};

    std::cout << result.get() << '\n';
}
