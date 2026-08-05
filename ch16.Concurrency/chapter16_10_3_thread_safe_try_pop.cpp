#include <iostream>
#include <mutex>
#include <optional>
#include <queue>

class TaskQueue
{
public:
    void Push(int value)
    {
        std::lock_guard lock{mutex};
        tasks.push(value);
    }

    std::optional<int> TryPop()
    {
        std::lock_guard lock{mutex};

        if (tasks.empty())
        {
            return std::nullopt;
        }

        const int value = tasks.front();
        tasks.pop();
        return value;
    }

private:
    std::mutex mutex;
    std::queue<int> tasks;
};

int main()
{
    TaskQueue queue;
    queue.Push(42);

    if (auto value = queue.TryPop())
    {
        std::cout << *value << '\n';
    }
}
