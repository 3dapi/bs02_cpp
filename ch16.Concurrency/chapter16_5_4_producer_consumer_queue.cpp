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

        // 대기 중인 스레드에 큐 상태 변경을 통지.
        condition.notify_one();
    }

    bool WaitPop(int& value)
    {
        std::unique_lock lock{mutex};

        // 작업이 들어오거나 종료 상태가 될 때까지 대기.
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

        // 종료 상태 변경을 모든 대기 스레드에 통지.
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

    // 소비자: 큐에서 작업을 꺼내 처리.
    std::jthread consumer{
        [&]
        {
            int value = 0;

            while (queue.WaitPop(value))
            {
                std::cout << value << '\n';
            }
        }};

    // 생산자: 작업을 만들어 큐에 저장.
    std::jthread producer{
        [&]
        {
            queue.Push(10);
            queue.Push(20);
            queue.Push(30);
            queue.Stop();
        }};
}
