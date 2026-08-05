#include <cstdint>
#include <iostream>
#include <limits>
using namespace std;

int main()
{
    int signedValue = 0xFFFFFFFF;
    unsigned int unsignedValue = 0xFFFFFFFFU;
    long largeValue = 10000000L;
    long long veryLargeValue = 0x7FFFFFFFFFFFFFFFLL;
    std::int32_t id = 100;
    std::uint64_t fileSize = 5000000000ULL;

    cout << "signedValue(int)           : " << signedValue << '\n';
    cout << "unsignedValue(unsigned int): " << unsignedValue << '\n';
    cout << "largeValue(long)           : " << largeValue << '\n';
    cout << "veryLargeValue(long long)  : " << veryLargeValue << '\n';
    cout << "id(int32_t)                : " << id << '\n';
    cout << "fileSize(uint64_t)         : " << fileSize << "\n\n";

#ifdef _MSC_VER
    cout << "__int64(Microsoft type) ---------\n";
    __int64 legacyValue = 100;
    cout << "sizeof(__int64)            : " << sizeof(__int64) << "byte\n";
    cout << "legacyValue(__int64)       : " << legacyValue << "\n\n";
#endif
}
