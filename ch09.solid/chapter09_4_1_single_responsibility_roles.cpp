#include <iostream>
#include <string_view>

class IDamageable
{
public:
    virtual ~IDamageable() = default;
    virtual int TakeDamage(int damage) = 0;
};

class Player : public IDamageable
{
public:
    int TakeDamage(int damage) override
    {
        hp -= damage;

        if (hp < 0)
        {
            hp = 0;
        }

        return damage;
    }

    int GetHp() const
    {
        return hp;
    }

private:
    int hp = 100;
};

class PlayerStatusView
{
public:
    void Draw(const Player& player) const
    {
        std::cout << "hp=" << player.GetHp() << '\n';
    }
};

class IAudioService
{
public:
    virtual ~IAudioService() = default;
    virtual void Play(std::string_view soundId) = 0;
};

class ConsoleAudioService : public IAudioService
{
public:
    void Play(std::string_view soundId) override
    {
        std::cout << soundId << '\n';
    }
};

int main()
{
    Player player;
    PlayerStatusView view;
    ConsoleAudioService audio;

    player.TakeDamage(20);
    view.Draw(player);
    audio.Play("player_hit");
}
