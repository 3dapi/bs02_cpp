#include <iostream>

decltype(auto)GetValue(int& value)
{
    return(value);
}

int main()
{
    int value{ 10 };
    decltype(value)first{ 20 };
    decltype((value))second{ value };
    double ratio{ 3.5 };
    decltype(value + ratio)result{ value + ratio };
    GetValue(value) = 30;
    std::cout << first << ' ' << second << ' ' << result << ' ' << value << '\n';
}
