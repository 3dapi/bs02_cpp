#include <atomic>
#include <iostream>

enum class State
{
    Idle,
    Running,
    Completed
};

int main()
{
    std::atomic<State> state = State::Idle;
    State expected = State::Idle;

    const bool changed = state.compare_exchange_strong(
        expected,
        State::Running);

    std::cout << std::boolalpha
              << changed << ' '
              << (state.load() == State::Running)
              << '\n';
}
