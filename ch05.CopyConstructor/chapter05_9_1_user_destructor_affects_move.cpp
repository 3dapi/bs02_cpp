#include <iostream>
#include <string>
#include <type_traits>

class Data
{
public:
    ~Data()
    {
    }

private:
    std::string value;
};

int main()
{
    std::cout << std::boolalpha;
    std::cout << std::is_move_constructible_v<Data> << '\n';
}
