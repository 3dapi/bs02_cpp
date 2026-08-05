#include <iostream>
#include <string>
#include <tuple>
#include <type_traits>

int main()
{
    using Data = std::tuple<int, std::string, double>;

    Data data{10, "Potion", 2.5};
    std::string& name = std::get<std::string>(data);

    static_assert(std::tuple_size_v<Data> == 3);
    static_assert(std::is_same_v<std::tuple_element_t<1, Data>, std::string>);

    name = "Ether";
    std::cout << std::get<0>(data) << ' '
              << std::get<1>(data) << ' '
              << std::get<2>(data) << '\n';
}
