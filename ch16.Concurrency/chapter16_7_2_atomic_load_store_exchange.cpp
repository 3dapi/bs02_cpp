#include <atomic>
#include <iostream>

int main()
{
    std::atomic<bool> ready = false;

    ready.store(true);
    const bool state = ready.load();
    const bool previous = ready.exchange(false);

    std::cout << std::boolalpha
              << state << ' '
              << previous << ' '
              << ready.load() << '\n';
}
