#include <iostream>
#include <string>
#include <variant>

struct Success
{
    std::string data;
};

struct Timeout
{
    int elapsedMilliseconds;
};

struct NetworkError
{
    int errorCode;
};

using RequestResult =
    std::variant<Success, Timeout, NetworkError>;

int main()
{
    RequestResult result = Timeout{5000};

    std::visit(
        [](const auto& state)
        {
            using T = std::remove_cvref_t<decltype(state)>;

            if constexpr (std::is_same_v<T, Success>)
            {
                std::cout << state.data << '\n';
            }
            else if constexpr (std::is_same_v<T, Timeout>)
            {
                std::cout << "timeout: "
                          << state.elapsedMilliseconds << '\n';
            }
            else
            {
                std::cout << "network error: "
                          << state.errorCode << '\n';
            }
        },
        result);
}
