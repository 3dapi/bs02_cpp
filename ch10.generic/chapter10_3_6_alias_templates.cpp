#include <cstddef>
#include <iostream>
#include <string>
#include <type_traits>

template <typename T, std::size_t Size>
class FixedArray
{
public:
    T& operator[](std::size_t index)
    {
        return values[index];
    }

private:
    T values[Size]{};
};

template <std::size_t Size>
using IntArray = FixedArray<int, Size>;

template <typename T>
using SmallArray = FixedArray<T, 8>;

template <typename T>
using RemoveConstReference =
    std::remove_const_t<std::remove_reference_t<T>>;

int main()
{
    IntArray<4> scores;
    SmallArray<std::string> names;

    scores[0] = 100;
    names[0] = "Knight";

    static_assert(
        std::is_same_v<SmallArray<int>, FixedArray<int, 8>>);
    static_assert(
        std::is_same_v<RemoveConstReference<const int&>, int>);

    std::cout << scores[0] << '\n';
    std::cout << names[0] << '\n';
}
