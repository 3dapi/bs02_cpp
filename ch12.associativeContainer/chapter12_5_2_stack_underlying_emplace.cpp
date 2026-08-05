#include <iostream>
#include <list>
#include <stack>
#include <string>
#include <utility>
#include <vector>

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
    std::stack<int, std::vector<int>> vectorStack;
    std::stack<int, std::list<int>> listStack;
    vectorStack.push(10);
    listStack.push(20);

    std::stack<Command> commands;
    commands.emplace("Move", 10);

    std::cout << vectorStack.top() << ' '
              << listStack.top() << '\n';
    std::cout << commands.top().name << ' '
              << commands.top().value << '\n';
}
