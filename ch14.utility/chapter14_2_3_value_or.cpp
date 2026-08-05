#include <iostream>
#include <optional>
#include <string>

int main()
{
    std::optional<int> port;
    int selectedPort = port.value_or(8080);

    std::optional<std::string> title;
    std::string selectedTitle = title.value_or("Untitled");

    std::cout << selectedPort << '\n';
    std::cout << selectedTitle << '\n';
}
