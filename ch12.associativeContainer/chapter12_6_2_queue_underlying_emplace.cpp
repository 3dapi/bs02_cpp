#include <iostream>
#include <list>
#include <queue>
#include <string>
#include <utility>

struct Command
{
    std::string name;
    int value;

    Command(std::string commandName, int commandValue)
        : name(std::move(commandName)), value(commandValue)
    {
    }
};

int main()
{
    std::queue<int, std::list<int>> listQueue;
    listQueue.push(10);

    std::queue<Command> commands;
    commands.emplace("Attack", 30);

    std::cout << listQueue.front() << '\n';
    std::cout << commands.front().name << ' '
              << commands.front().value << '\n';
}
