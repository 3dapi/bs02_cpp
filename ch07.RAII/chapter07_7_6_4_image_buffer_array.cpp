#include <cstddef>
#include <iostream>
#include <memory>

class ImageBuffer
{
public:
    ImageBuffer(int width, int height)
        : width(width),
          height(height),
          pixels(std::make_unique<unsigned int[]>(
              static_cast<std::size_t>(width) * height
          ))
    {
    }

    std::size_t PixelCount() const
    {
        return static_cast<std::size_t>(width)
            * static_cast<std::size_t>(height);
    }

private:
    int width;
    int height;
    std::unique_ptr<unsigned int[]> pixels;
};

int main()
{
    ImageBuffer image(640, 480);

    std::cout << image.PixelCount() << '\n';
}
