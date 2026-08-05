#include <iostream>

namespace Library
{
    inline namespace V2
    {
        void Print()
        {
            std::cout << "V2\n";
        }
    }
}

int main()
{
    Library::Print();
    Library::V2::Print();
}
