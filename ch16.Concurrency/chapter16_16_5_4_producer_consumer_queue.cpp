#include <condition_variable>
#include <iostream>
#include <mutex>
#include <queue>
#include <thread>

class TaskQueue
{
public:
    void Push(int value)
    {
        {
            std::lock_guard lock{mutex};
            tasks.push(value);
        }

        condition.notify_one();
    }

    bool Pop(int& value)
    {
        std::unique_lock lock{mutex};

        condition.wait(lock, [&]
        {
            return !tasks.empty() || stopped;
        });

        if (tasks.empty())
        {
            return false;
        }

        value = tasks.front();
        tasks.pop();
        return true;
    }

    void Stop()
    {
        {
            std::lock_guard lock{mutex};
            stopped = true;
        }

        condition.notify_all();
    }

private:
    std::mutex mutex;
    std::condition_variable condition;
    std::queue<int> tasks;
    bool stopped = false;
};

int main()
{
    TaskQueue queue;
    int total = 0;

    std::jthread consumer{
        [&]
        {
            int value = 0;

            while (queue.Pop(value))
            {
                total += value;
            }
        }};

    queue.Push(10);
    queue.Push(20);
    queue.Push(30);
    queue.Stop();
    consumer.join();

    std::cout << total << '\n';
}
