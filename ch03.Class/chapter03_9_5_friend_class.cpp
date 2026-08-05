#include <iostream>

class GameData
{
    friend class SaveSystem;

public:
    int GetStage() const
    {
        return stage;
    }

private:
    int score = 0, stage = 1;
};

class SaveSystem
{
public:
    static void Save(const GameData& data)
    {
        std::cout << "Score: " << data.score << '\n';
        std::cout << "Stage: " << data.stage << '\n';
    }
};

int main()
{
    GameData gameData;

    SaveSystem::Save(gameData);
}
