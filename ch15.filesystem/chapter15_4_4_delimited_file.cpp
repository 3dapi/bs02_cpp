#include <filesystem>
#include <fstream>
#include <iostream>
#include <optional>
#include <sstream>
#include <string>
#include <utility>
#include <vector>

struct Item
{
    int id;
    std::string name;
    int count;
};

std::optional<int> ParseInteger(const std::string& text)
{
    std::istringstream input{text};
    int value = 0;

    if (!(input >> value))
    {
        return std::nullopt;
    }

    input >> std::ws;
    if (!input.eof())
    {
        return std::nullopt;
    }

    return value;
}

int main()
{
    const std::filesystem::path path = "chapter15_items.csv";

    {
        std::ofstream output{path};
        output << "1001,Potion,10\n1002,Ether,5\n";
    }

    std::ifstream file{path};
    std::vector<Item> items;
    std::string line;

    while (std::getline(file, line))
    {
        std::istringstream record{line};
        std::string idText;
        std::string name;
        std::string countText;

        if (!std::getline(record, idText, ',') ||
            !std::getline(record, name, ',') ||
            !std::getline(record, countText))
        {
            continue;
        }

        auto id = ParseInteger(idText);
        auto count = ParseInteger(countText);

        if (!id || !count)
        {
            continue;
        }

        items.push_back(Item{*id, std::move(name), *count});
    }

    std::cout << items.size() << '\n';
    file.close();
    std::filesystem::remove(path);
}
