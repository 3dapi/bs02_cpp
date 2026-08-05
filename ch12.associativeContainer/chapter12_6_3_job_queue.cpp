#include <iostream>
#include <queue>
#include <string>
#include <utility>

struct Job
{
    int id;
    std::string description;
};

int main()
{
    std::queue<Job> jobs;

    jobs.push({1, "Load texture"});
    jobs.push({2, "Create mesh"});
    jobs.push({3, "Save scene"});

    while (!jobs.empty())
    {
        Job job = std::move(jobs.front());
        jobs.pop();

        std::cout << job.id << ": " << job.description << '\n';
    }
}
