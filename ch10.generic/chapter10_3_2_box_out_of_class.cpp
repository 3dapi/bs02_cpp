#include <iostream>
#include <string>

template <typename T>
class Box
{
public:
    explicit Box(const T& value);

    const T& GetValue() const;
    void SetValue(const T& value);

private:
    T value;
};

template <typename T>
Box<T>::Box(const T& value)
    : value(value)
{
}

template <typename T>
const T& Box<T>::GetValue() const
{
    return value;
}

template <typename T>
void Box<T>::SetValue(const T& value)
{
    this->value = value;
}

int main()
{
    Box<std::string> box("Knight");
    box.SetValue("Mage");

    std::cout << box.GetValue() << '\n';
}
