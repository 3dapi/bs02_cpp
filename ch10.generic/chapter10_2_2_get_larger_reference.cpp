#include <iostream>
#include <string>

template <typename T>
const T& GetLarger(const T& left, const T& right)
{
    return left < right ? right : left;
}

int main()
{
    std::string first = "Knight";
    std::string second = "Mage";

    const std::string& result = GetLarger(first, second);
    std::cout << result << '\n';

    // 임시 객체를 전달한 뒤 반환 참조를 보관하면 수명에 주의해야 한다.
}
