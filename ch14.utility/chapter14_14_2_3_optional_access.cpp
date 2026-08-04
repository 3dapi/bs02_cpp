#include <iostream>
#include <optional>
#include <string>

int main()
{
    std::optional<std::string> name = "Alice";

    if (name.has_value())
    {
        std::cout << *name << '\n';
        std::cout << name->size() << '\n';
        std::cout << name.value() << '\n';
    }

    name.reset();

    try
    {
        std::cout << name.value() << '\n';
    }
    catch (const std::bad_optional_access&)
    {
        std::cout << "no value\n";
    }
}
