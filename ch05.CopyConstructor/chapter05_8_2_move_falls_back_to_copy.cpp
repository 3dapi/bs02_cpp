#include <iostream>
#include <utility>

class CopyOnly
{
public:
    CopyOnly() = default;

    CopyOnly(const CopyOnly&)
    {
        std::cout << "copy\n";
    }
};

int main()
{
    CopyOnly first;
    CopyOnly second(std::move(first));

    static_cast<void>(second);
}
