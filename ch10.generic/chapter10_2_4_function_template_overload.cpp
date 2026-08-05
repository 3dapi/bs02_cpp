#include <iostream>

void Print(int value)
{
    std::cout << "int: " << value << '\n';
}

template <typename T>
void Print(const T& value)
{
    std::cout << typeid(T).name() << ": template: " << value << '\n';
}

void Show(long value)
{
    std::cout << "long: " << value << '\n';
}

template <typename T>
void Show(T value)
{
    std::cout << typeid(T).name() << ": template: " << value << '\n';
}
int main()
{
    Print(10);      // 일반 함수 Print(int)
    Print(3.5);     // 함수 템플릿 Print<double>

    Show(10);       // 함수 템플릿 Show<int>
}
