#include <iostream>
#include <mutex>
#include <string>

int main()
{
    std::mutex mutex;
    std::string sharedData = "saved data";
    std::string snapshot;

    {
        std::lock_guard lock{mutex};
        snapshot = sharedData;
    }

    std::cout << snapshot << '\n';
}
