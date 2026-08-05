#include <iostream>

class Player
{
public:
    explicit Player(int id)
        : id(id)
    {
    }

    int GetId() const
    {
        return id;
    }

private:
    int id;
};

class Party
{
public:
    bool AddMember(Player* player);

    int GetMemberCount() const
    {
        return memberCount;
    }

private:
    Player* members[4] = {};
    int memberCount = 0;
};

bool Party::AddMember(Player* player)
{
    if (player == nullptr || memberCount >= 4)
    {
        return false;
    }

    members[memberCount] = player;
    ++memberCount;

    return true;
}

int main()
{
    Player first(1);
    Player second(2);
    Party party;

    party.AddMember(&first);
    party.AddMember(&second);

    std::cout << party.GetMemberCount() << '\n';
}
