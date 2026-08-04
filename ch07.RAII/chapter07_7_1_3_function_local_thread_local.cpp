#include <iostream>

int NextThreadLocalId()
{
    thread_local int id = 0;

    return ++id;
}

int main()
{
    std::cout << NextThreadLocalId() << '\n';
    std::cout << NextThreadLocalId() << '\n';
}
