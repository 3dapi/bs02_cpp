#include <iostream>

class NonCopyable
{
public:
    NonCopyable() = default;
    NonCopyable(const NonCopyable&) = delete;
};

class Holder
{
public:
    bool IsValid() const
    {
        return true;
    }

private:
    NonCopyable value;
};

int main()
{
    Holder first;

    // Holder second = first;  // 오류

    std::cout << std::boolalpha << first.IsValid() << '\n';
}
