#include <iostream>
#include <string>
#include <tuple>

int main()
{
    int id = 0;
    std::string name;
    int hp = 0;

    std::tie(id, name, hp) =
        std::make_tuple(1, std::string{"Knight"}, 100);

    std::cout << id << ' ' << name << ' ' << hp << '\n';

    std::tie(id, std::ignore, hp) =
        std::make_tuple(2, std::string{"Mage"}, 80);

    std::cout << id << ' ' << name << ' ' << hp << '\n';
}
