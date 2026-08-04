#include <functional>
#include <iostream>
#include <mutex>

int main()
{
    std::mutex mutex;
    std::function<void()> callback = []
    {
        std::cout << "notified\n";
    };

    std::function<void()> localCallback;

    {
        std::lock_guard lock{mutex};
        localCallback = callback;
    }

    if (localCallback)
    {
        localCallback();
    }
}
