#include <algorithm>
#include <cstddef>
#include <functional>
#include <iostream>
#include <utility>
#include <vector>

class Event
{
public:
    using Handler = std::function<void(int)>;
    using HandlerId = std::size_t;

    HandlerId AddHandler(Handler handler)
    {
        const HandlerId id = nextId++;
        handlers.emplace_back(id, std::move(handler));
        return id;
    }

    void RemoveHandler(HandlerId id)
    {
        std::erase_if(
            handlers,
            [id](const auto& entry)
            {
                return entry.first == id;
            });
    }

    void Notify(int value) const
    {
        for (const auto& [id, handler] : handlers)
        {
            (void)id;
            handler(value);
        }
    }

private:
    HandlerId nextId = 1;
    std::vector<std::pair<HandlerId, Handler>> handlers;
};

int main()
{
    Event event;

    Event::HandlerId first = event.AddHandler([](int value)
    {
        std::cout << "first: " << value << '\n';
    });

    event.AddHandler([](int value)
    {
        std::cout << "second: " << value << '\n';
    });

    event.Notify(10);
    event.RemoveHandler(first);
    event.Notify(20);
}
