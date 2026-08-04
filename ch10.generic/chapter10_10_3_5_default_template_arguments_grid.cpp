#include <cstddef>
#include <iostream>
#include <stdexcept>

template <typename T = int,
          std::size_t Width = 10,
          std::size_t Height = 10>
class Grid
{
public:
    T& At(std::size_t x, std::size_t y)
    {
        if (x >= Width || y >= Height)
        {
            throw std::out_of_range("Grid index out of range");
        }

        return values[y][x];
    }

private:
    T values[Height][Width]{};
};

int main()
{
    Grid<> defaultGrid;
    Grid<float> floatGrid;
    Grid<float, 20> wideGrid;
    Grid<float, 20, 30> customGrid;

    defaultGrid.At(0, 0) = 10;
    floatGrid.At(0, 0) = 1.5f;
    wideGrid.At(19, 0) = 2.5f;
    customGrid.At(19, 29) = 3.5f;

    std::cout << defaultGrid.At(0, 0) << '\n';
    std::cout << customGrid.At(19, 29) << '\n';
}
