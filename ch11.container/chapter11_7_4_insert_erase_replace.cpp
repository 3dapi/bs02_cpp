#include <iostream>
#include <string>

int main()
{
    std::string text = "Hello World";
    text.insert(5, ",");
    text.erase(5, 1);

    std::string item = "red potion";
    item.replace(0, 3, "blue");

    std::string letters = "ABC";
    letters.push_back('D');
    letters.pop_back();

    std::cout << text << '\n'
              << item << '\n'
              << letters << '\n';
}
