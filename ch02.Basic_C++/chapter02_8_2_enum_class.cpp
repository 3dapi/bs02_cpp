#include <iostream>

enum class State: unsigned char
{
    Idle, Running, Finished
};

int main()
{
    State state{ State::Running };
    int value{ static_cast<int>(state) };
    std::cout << value << '\n';
}
