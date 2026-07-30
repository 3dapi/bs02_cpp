#include <iostream>

class GameConfig
{
public:
    inline static int maxPlayerCount = 4;
    inline static const int minimumPlayerCount = 1;
    static constexpr int maximumStageCount = 100;
};

int main()
{
    std::cout << GameConfig::maxPlayerCount << '\n';
    std::cout << GameConfig::minimumPlayerCount << '\n';
    std::cout << GameConfig::maximumStageCount << '\n';
}
