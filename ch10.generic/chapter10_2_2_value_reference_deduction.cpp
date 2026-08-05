#include <type_traits>

template <typename T>
void InspectValue(T value)
{
    static_assert(std::is_same_v<T, int>);
    value = 20;
    (void)value;
}

template <typename T>
void InspectReference(T& value)
{
    static_assert(std::is_same_v<T, const int>);
    (void)value;
}

int main()
{
    const int number = 10;

    InspectValue(number);
    InspectReference(number);
}
