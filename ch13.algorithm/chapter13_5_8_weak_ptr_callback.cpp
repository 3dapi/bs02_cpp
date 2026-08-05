#include <iostream>
#include <memory>

class Task
{
public:
    void Run()
    {
        std::cout << "run\n";
    }
};

int main()
{
    std::shared_ptr<Task> task = std::make_shared<Task>();
    std::weak_ptr<Task> weak = task;

    auto callback = [weak]
    {
        if (std::shared_ptr<Task> locked = weak.lock())
        {
            locked->Run();
        }
        else
        {
            std::cout << "expired\n";
        }
    };

    callback();
    task.reset();
    callback();
}
