#include <algorithm>
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <string>
#include <string_view>
#include <utility>

class HealthComponent
{
public:
    explicit HealthComponent(int maxHp)
        : hp(maxHp), maxHp(maxHp)
    {
    }

    int TakeDamage(int damage)
    {
        const int oldHp = hp;
        hp = std::max(hp - std::max(damage, 0), 0);
        return oldHp - hp;
    }

    int GetHp() const
    {
        return hp;
    }

    int GetMaxHp() const
    {
        return maxHp;
    }

private:
    int hp;
    int maxHp;
};

struct PlayerData
{
    std::string name;
    int hp;
    int maxHp;
};

class Player
{
public:
    Player(std::string name, int maxHp)
        : name(std::move(name)), health(maxHp)
    {
    }

    int TakeDamage(int damage)
    {
        return health.TakeDamage(damage);
    }

    std::string_view GetName() const
    {
        return name;
    }

    PlayerData ExportData() const
    {
        return PlayerData
        {
            name,
            health.GetHp(),
            health.GetMaxHp()
        };
    }

private:
    std::string name;
    HealthComponent health;
};

class IPlayerRepository
{
public:
    virtual ~IPlayerRepository() = default;
    virtual void Save(const PlayerData& data) = 0;
};

class TextPlayerRepository : public IPlayerRepository
{
public:
    explicit TextPlayerRepository(std::string fileName)
        : fileName(std::move(fileName))
    {
    }

    void Save(const PlayerData& data) override
    {
        std::ofstream output(fileName);

        if (!output)
        {
            throw std::runtime_error("cannot open player file");
        }

        output << data.name << ','
               << data.hp << ','
               << data.maxHp;
    }

private:
    std::string fileName;
};

int main()
{
    Player player("Knight", 150);
    player.TakeDamage(30);

    TextPlayerRepository repository("chapter09_player.txt");
    repository.Save(player.ExportData());

    std::cout << player.GetName() << '\n';
}
