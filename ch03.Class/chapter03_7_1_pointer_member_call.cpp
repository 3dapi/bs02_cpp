#include <iostream>

class Player
{
public:
    void Move(float offsetX, float offsetY)
    {
        x += offsetX;
        y += offsetY;
    }

    void Print() const
    {
        std::cout << x << ", " << y << '\n';
    }

private:
    float x = 0.0f, y = 0.0f;
};

int main()
{
    Player player;
    Player* selectedPlayer = &player;

    selectedPlayer->Move(10.0f, 20.0f);
    (*selectedPlayer).Move(5.0f, -10.0f);

    player.Print();
}
