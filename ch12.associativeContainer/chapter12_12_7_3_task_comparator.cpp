#include <cstdint>
#include <iostream>
#include <queue>
#include <vector>

struct Task
{
    int id;
    int priority;
    std::uint64_t sequence;
};

struct CompareTask
{
    bool operator()(const Task& left, const Task& right) const
    {
        if (left.priority != right.priority)
        {
            return left.priority < right.priority;
        }

        return left.sequence > right.sequence;
    }
};

int main()
{
    std::priority_queue<Task, std::vector<Task>, CompareTask> tasks;

    tasks.push({1, 10, 0});
    tasks.push({2, 30, 1});
    tasks.push({3, 30, 2});

    while (!tasks.empty())
    {
        std::cout << tasks.top().id << ' ';
        tasks.pop();
    }
    std::cout << '\n';
}
