#include <iostream>

class GameData
{
public:
    int GetScore() const
    {
        return score;
    }

private:
    int score = 0;
};

void PrintScore(const GameData& data)
{
    std::cout << data.GetScore() << '\n';
}

int main()
{
    GameData data;

    PrintScore(data);
}
