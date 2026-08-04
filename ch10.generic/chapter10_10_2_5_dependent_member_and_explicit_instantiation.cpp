#include <iostream>

template <typename T>
void PrintName(const T& value)
{
    std::cout << value.GetName() << '\n';
}

class Player
{
public:
    const char* GetName() const
    {
        return "Player";
    }
};

template <typename T>
T Multiply(T left, T right)
{
    return left * right;
}

template int Multiply<int>(int, int);

int main()
{
    Player player;
    PrintName(player);

    std::cout << Multiply(3, 4) << '\n';

    // PrintName(10); // int에는 GetName()이 없음
}
