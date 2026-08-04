#include <iostream>
#include <string>

struct Item
{
    int id;
    std::string name;
    int count;
};

std::ostream& operator<<(std::ostream& output, const Item& item)
{
    output << item.id << ' '
           << item.name << ' '
           << item.count;

    return output;
}

int main()
{
    Item item{1001, "Potion", 10};
    std::cout << item << " stored\n";
}
