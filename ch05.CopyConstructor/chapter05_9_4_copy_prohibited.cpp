#include <iostream>

class UniqueFile
{
public:
    UniqueFile() = default;

    UniqueFile(const UniqueFile&) = delete;
    UniqueFile& operator=(const UniqueFile&) = delete;

    bool IsOpen() const
    {
        return true;
    }
};

int main()
{
    UniqueFile first;

    // UniqueFile second = first;  // 오류

    std::cout << std::boolalpha << first.IsOpen() << '\n';
}
