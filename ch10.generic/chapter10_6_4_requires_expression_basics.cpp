#include <iostream>
#include <string>
#include <vector>

template <typename T>
concept HasSize = requires(const T& value)
{
    value.size();
};

template <typename T>
concept HasValueType = requires
{
    typename T::value_type;
};

template <HasSize T>
void PrintSize(const T& value)
{
    std::cout << value.size() << '\n';
}

template <HasValueType T>
void PrintValueTypeAvailable(const T&)
{
    std::cout << "value_type available\n";
}

int main()
{
    std::vector<int> values{1, 2, 3};
    std::string text = "Knight";

    PrintSize(values);
    PrintSize(text);
    PrintValueTypeAvailable(values);
}
