#include <iostream>
#include <sstream>
#include <string>

int main()
{
    std::string record = "1001,Potion,10";
    std::istringstream input{record};

    std::string idText;
    std::string name;
    std::string countText;

    std::getline(input, idText, ',');
    std::getline(input, name, ',');
    std::getline(input, countText);

    std::cout << idText << ' ' << name << ' ' << countText << '\n';
}
