#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;

void MemoryAllocFree()
{
    char* memory = static_cast<char*>(malloc(100 * sizeof(char)));
    if (memory != nullptr)
    {
        memset(memory, 0, 100);
        cout << static_cast<int>(memory[0]) << '\n';
        free(memory);
    }
}

int main()
{
    MemoryAllocFree();
}
