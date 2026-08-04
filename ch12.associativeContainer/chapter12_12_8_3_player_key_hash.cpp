#include <functional>
#include <iostream>
#include <string>
#include <unordered_map>

struct PlayerKey
{
    int serverId;
    int playerId;

    bool operator==(const PlayerKey&) const = default;
};

struct PlayerKeyHash
{
    std::size_t operator()(const PlayerKey& key) const noexcept
    {
        std::size_t first = std::hash<int>{}(key.serverId);
        std::size_t second = std::hash<int>{}(key.playerId);
        return first ^ (second << 1);
    }
};

int main()
{
    std::unordered_map<PlayerKey, std::string, PlayerKeyHash> playerNames;
    playerNames.insert({PlayerKey{1, 1001}, "Knight"});

    std::cout << playerNames.at(PlayerKey{1, 1001}) << '\n';
}
