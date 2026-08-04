#include <iostream>
#include <span>
#include <vector>

int main()
{
    std::vector<int> values;
    values.reserve(3);
    values.push_back(10);
    values.push_back(20);
    values.push_back(30);

    std::span<int> view{values};
    const int* oldAddress = view.data();

    values.push_back(40);
    const int* newAddress = values.data();

    std::cout << std::boolalpha
              << (oldAddress == newAddress)
              << '\n';
    std::cout << view.size() << ' ' << values.size() << '\n';

    // 재할당이 발생했다면 기존 view를 원소 접근에 사용하지 않는다.
}
