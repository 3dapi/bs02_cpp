// new[]와 delete[]를 사용한 동적 메모리 할당과 해제
void MemoryNewDelete()
{
    // new[] 로 객체 배열을 생성하고, ()를 사용하여 모든 배열 요소를 0으로 초기화.
    char* memory = new char[100]();

    // ... 메모리 사용 ...

    // 메모리 사용 후 delete[]로 해제.
    delete[] memory;
}

#include <new>
// std::nothrow를 적용, 할당 실패를 nullptr로 확인
void MemoryNewDeleteNothrow()
{
    char* memory = new (std::nothrow) char[100]();
    if(memory != nullptr)
    {
        delete[] memory;
    }
}
