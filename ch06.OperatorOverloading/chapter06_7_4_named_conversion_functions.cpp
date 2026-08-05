#include <iostream>
#include <string>

class FileSize
{
public:
    explicit FileSize(long long bytes)
        : bytes(bytes)
    {
    }

    long long Bytes() const
    {
        return bytes;
    }

    std::string ToString() const
    {
        return std::to_string(bytes) + " bytes";
    }

private:
    long long bytes = 0;
};

int main()
{
    FileSize size(4096);

    std::cout << size.Bytes() << '\n';
    std::cout << size.ToString() << '\n';
}
