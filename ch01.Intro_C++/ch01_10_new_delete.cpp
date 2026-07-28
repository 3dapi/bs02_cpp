#include <new>

// 단일 객체 new -> delete
int* single = new (std::nothrow) int(200);
if (single != nullptr)
{
    delete single;
}

// 객체 배열: new [] -> delete[]
int* values = new (std::nothrow) int[1000]();
if (values != nullptr)
{
    delete[] values;
}

