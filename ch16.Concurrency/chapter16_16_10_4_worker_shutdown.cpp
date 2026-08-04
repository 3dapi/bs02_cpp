#include <condition_variable>
#include <iostream>
#include <mutex>
#include <queue>
#include <thread>

class Worker
{
public:
    Worker()
        : thread{[this]
        {
            Run();
        }}
    {
    }

    ~Worker()
    {
        {
            std::lock_guard lock{mutex};
            accepting = false;
            stopping = true;
        }

        condition.notify_all();
    }

    bool Push(int value)
    {
        {
            std::lock_guard lock{mutex};

            if (!accepting)
            {
                return false;
            }

            tasks.push(value);
        }

        condition.notify_one();
        return true;
    }

    int GetTotal() const
    {
        std::lock_guard lock{mutex};
        return total;
    }

private:
    void Run()
    {
        while (true)
        {
            int value = 0;

            {
                std::unique_lock lock{mutex};

                condition.wait(lock, [this]
                {
                    return !tasks.empty() || stopping;
                });

                if (tasks.empty())
                {
                    return;
                }

                value = tasks.front();
                tasks.pop();
            }

            {
                std::lock_guard lock{mutex};
                total += value;
            }
        }
    }

    mutable std::mutex mutex;
    std::condition_variable condition;
    std::queue<int> tasks;
    bool accepting = true;
    bool stopping = false;
    int total = 0;
    std::jthread thread;
};

int main()
{
    Worker worker;
    worker.Push(10);
    worker.Push(20);
    worker.Push(30);

    std::this_thread::yield();
    std::cout << (worker.GetTotal() >= 0) << '\n';
}
