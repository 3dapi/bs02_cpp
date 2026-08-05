#include <iostream>

int value = 10;
namespace Game
{
    int value = 20;
    void Print()
    {
        std::cout << value << ' ' << ::value << '\n';
    }
}
namespace G = Game;

int main()
{
    G::Print();
}
