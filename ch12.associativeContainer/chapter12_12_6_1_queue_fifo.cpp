#include <iostream>
#include <queue>
#include <string>

int main()
{
    std::queue<std::string> messages;

    messages.push("Connect");
    messages.push("Load");
    messages.push("Start");

    std::cout << messages.front() << '\n';
    messages.pop();
    std::cout << messages.front() << '\n';
    std::cout << messages.back() << '\n';
}
