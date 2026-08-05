#include <iostream>
#include <sstream>
#include <string>
#include <utility>

struct Item
{
    int id;
    std::string name;
    int count;
};

std::istream& operator>>(std::istream& input, Item& item)
{
    int id = 0;
    std::string name;
    int count = 0;

    if (!(input >> id >> name >> count))
    {
        return input;
    }

    if (id <= 0 || count < 0)
    {
        input.setstate(std::ios::failbit);
        return input;
    }

    item = Item{id, std::move(name), count};
    return input;
}

int main()
{
    Item item{1, "Old", 1};
    std::istringstream input{"1001 Potion 10"};

    if (input >> item)
    {
        std::cout << item.id << ' '
                  << item.name << ' '
                  << item.count << '\n';
    }
}
