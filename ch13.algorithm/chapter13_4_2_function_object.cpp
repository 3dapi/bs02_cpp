#include <algorithm>
#include <iostream>
#include <vector>

// IsGreaterThan 클래스 정의.
class IsGreaterThan
{
public:
    explicit IsGreaterThan(int limit): limit(limit)
    {
    }
    // 함수 호출 연산자.
    bool operator()(int value) const
    {
        return value > limit;
    }
private:
    int limit;
};

int main()
{
    std::vector<int> values{10, 25, 40, 5, 66, 75};
    // 함수 객체 생성.
    auto gt = IsGreaterThan{20};
    // 함수 객체 전달.
    auto count = std::count_if(values.begin(), values.end(), gt);
    std::cout << count << '\n';

    // 임시 함수 객체 직접 전달.
    count = std::count_if(values.begin(), values.end(), IsGreaterThan{40});
    std::cout << count << '\n';
}
