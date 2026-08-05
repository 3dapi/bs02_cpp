#include <iostream>
#include <stack>
#include <string>

int main()
{
    std::stack<std::string> undoHistory;
    undoHistory.push("Create object");
    undoHistory.push("Move object");
    undoHistory.push("Delete object");

    while (!undoHistory.empty())
    {
        std::cout << "undo: " << undoHistory.top() << '\n';
        undoHistory.pop();
    }
}
