#include <iostream>
#include <vector>

int main()
{
    std::vector<int> reserved;
    reserved.reserve(10);

    std::vector<int> resized{10, 20};
    resized.resize(5);
    resized.resize(8, -1);
    resized.resize(2);

    std::cout << "reserved size=" << reserved.size()
              << " capacity=" << reserved.capacity()
              << '\n';

    std::cout << "resized size=" << resized.size()
              << " capacity=" << resized.capacity()
              << '\n';
}
