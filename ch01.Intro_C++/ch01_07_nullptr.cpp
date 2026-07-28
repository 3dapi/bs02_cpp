#include <iostream>
using namespace std;
 
void PrintMessage(/*매개 변수 없으면 void 안씀. 빈 괄호 유지*/)
{
    cout << "반환값이 없는 함수입니다.\n";
} 
 
int main()
{
    PrintMessage();
 
    int value = 100;
    void* memory = &value;

    cout << "객체의 주소: " << memory << '\n';
 
    int* pointer = nullptr;
     if(pointer == nullptr)
        cout << "pointer는 널 포인터입니다.\n";
 }
