#include <iostream>
#include <vector>

using UInt = unsigned int;
using ScoreList = std::vector<int>;
using Callback = void(*)(int);

void OnEvent(int value)
{
    std::cout << value << '\n';
}

int main()
{
    UInt value{ 10U };
    ScoreList scores{ 100, 200, 300 };
    Callback callback{ OnEvent };
    callback(static_cast<int>(value + scores.size()));
}
