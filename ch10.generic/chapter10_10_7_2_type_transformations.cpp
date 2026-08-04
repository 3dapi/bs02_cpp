#include <type_traits>

int main()
{
    using First = std::remove_reference_t<int&>;
    using Second = std::remove_reference_t<const int&&>;
    using Value = std::remove_cv_t<const volatile int>;
    using Raw = std::remove_cvref_t<const int&>;
    using Pointer = std::add_pointer_t<int>;
    using Pointee = std::remove_pointer_t<int*>;
    using ArrayType = int[5];
    using DecayedArray = std::decay_t<ArrayType>;

    static_assert(std::is_same_v<First, int>);
    static_assert(std::is_same_v<Second, const int>);
    static_assert(std::is_same_v<Value, int>);
    static_assert(std::is_same_v<Raw, int>);
    static_assert(std::is_same_v<Pointer, int*>);
    static_assert(std::is_same_v<Pointee, int>);
    static_assert(std::is_same_v<DecayedArray, int*>);
}
