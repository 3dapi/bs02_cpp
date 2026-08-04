#include <concepts>
#include <iostream>
#include <memory>
#include <string>
#include <utility>

template <typename T, typename... Args>
requires std::constructible_from<T, Args...>
std::unique_ptr<T> CreateObject(Args&&... args)
{
    return std::make_unique<T>(
        std::forward<Args>(args)...);
}

class Character
{
public:
    Character(std::string name, int hp)
        : name(std::move(name)), hp(hp)
    {
    }

    const std::string& GetName() const
    {
        return name;
    }

    int GetHp() const
    {
        return hp;
    }

private:
    std::string name;
    int hp;
};

int main()
{
    std::string name = "Knight";

    auto first = CreateObject<Character>(name, 100);
    auto second = CreateObject<Character>(
        std::string("Mage"), 80);

    std::cout << first->GetName() << ", "
              << first->GetHp() << '\n';
    std::cout << second->GetName() << ", "
              << second->GetHp() << '\n';
}
