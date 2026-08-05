#include <iostream>
#include <string>
#include <vector>

int main()
{
    std::string message = "Hello";
    message += ", ";
    message += "C++";

    std::string firstName = "Ada";
    std::string lastName = "Lovelace";
    std::string fullName = firstName + " " + lastName;

    std::vector<std::string> words{"one", "two", "three"};
    std::string result;
    result.reserve(32);

    for (const std::string& word : words)
    {
        result += word;
        result += ' ';
    }

    std::cout << message << '\n'
              << fullName << '\n'
              << result << '\n'
              << std::boolalpha
              << (std::string("apple") < std::string("banana"))
              << '\n';
}
