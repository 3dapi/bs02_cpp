#include <iostream>
using namespace std;

class ExpSpec
{
public:
    explicit ExpSpec(int value) : value(value)
    {
        cout << "ExpSpec: " << value << '\n';
    }

    int GetValue() const { return value; }

    ExpSpec& operator =(const ExpSpec& rhs)
    {
        value = rhs.value;
        return *this;
    }

private:
    int value;
};


int main()
{
    ExpSpec r1{ 100 };
    ExpSpec r2 = r1;
    r2 = r1;

    // 생성자에 explicit가 암시적 변환 허용 안함.
    //ExpSpec r3 = 400;

    cout << r1.GetValue() << '\n';

    return 0;
}