#include <iostream>
#include <concepts> // type_traits 대신 concepts 헤더 추가
#include <utility>

int GetValue()
{
    return 100;
}

int& GetReference()
{
    static int value = 10;
    return value;
}

int&& GetRvalueReference()
{
    static int value = 20;
    return std::move(value);
}

int main()
{
    int value = 10;
    int& reference = value;
    int&& rvalueReference = 100;

    std::cout << std::boolalpha;

    // decltype((expr))는 표현식의 값 범주(value category)를 반영해 타입을 얻는 형태
    // lvalue → T&, xvalue → T&&, prvalue → T

    // glvalue 샘플 - xvalue 제외
    std::cout << "value : " << std::same_as<decltype((value)), int&> << '\n';
    std::cout << "GetReference() : " << std::same_as<decltype((GetReference())), int&> << '\n';

    // lvalue 샘플
    std::cout << "reference : " << std::same_as<decltype((reference)), int&> << '\n';
    std::cout << "rvalueReference : " << std::same_as<decltype((rvalueReference)), int&> << '\n';

    // xvalue 샘플
    std::cout << "std::move(value) : " << std::same_as<decltype((std::move(value))), int&&> << '\n';
    std::cout << "GetRvalueReference() : " << std::same_as<decltype((GetRvalueReference())), int&&> << '\n';

    // prvalue 샘플
    std::cout << "100 : " << std::same_as<decltype((100)), int> << '\n';
    std::cout << "value + 10 : " << std::same_as<decltype((value + 10)), int> << '\n';
    std::cout << "GetValue() : " << std::same_as<decltype((GetValue())), int> << '\n';

    // rvalue 샘플 - prvalue 제외
    std::cout << "std::move(value) : " << std::same_as<decltype((std::move(value))), int&&> << '\n';
    std::cout << "GetRvalueReference() : " << std::same_as<decltype((GetRvalueReference())), int&&> << '\n';
}
