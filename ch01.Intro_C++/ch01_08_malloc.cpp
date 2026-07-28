// C++에서 C 라이브러리를 사용한 동적 메모리 할당과 해제
#include <cstdlib>
#include <cstring>
using namespace std;

void MemoryAllocFree()
{
    char* memory = static_cast<char*>(malloc(100 * sizeof(char)));
    if(memory != nullptr)
    {
        memset(memory, 0, 100);
        free(memory);
    }
}
