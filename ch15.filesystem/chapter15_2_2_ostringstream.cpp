#include <iostream>
#include <sstream>
#include <string>

std::string MakeItemText(int id, const std::string& name, int count)
{
    std::ostringstream output;
    output << "Item{" << id
           << ", " << name
           << ", " << count
           << '}';

    return output.str();
}

int main()
{
    std::cout << MakeItemText(1001, "Potion", 10) << '\n';
}
