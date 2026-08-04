#include <atomic>
#include <iostream>
#include <thread>

std::atomic<int> state = 0;

void Consumer()
{
    state.wait(0);
    std::cout << state.load() << '\n';
}

int main()
{
    std::jthread worker{Consumer};

    state.store(1);
    state.notify_one();
}
