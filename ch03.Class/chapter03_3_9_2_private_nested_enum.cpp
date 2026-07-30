#include <iostream>

class NetworkConnection
{
public:
    bool IsConnected() const
    {
        return state == State::Connected;
    }

    void Connect()
    {
        state = State::Connected;
    }

private:
    enum class State
    {
        Disconnected,
        Connecting,
        Connected
    };

    State state = State::Disconnected;
};

int main()
{
    NetworkConnection connection;

    connection.Connect();

    if (connection.IsConnected())
    {
        std::cout << "연결됨\n";
    }
}
