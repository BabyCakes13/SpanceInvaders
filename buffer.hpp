#ifndef BUFFER_H_
#define BUFFER_H_

#include <cstdint>

class Buffer {
    private:
        std::size_t width;
        std::size_t height;
        uint32_t *data;

    public:
        ~Buffer();
        Buffer(std::size_t width, std::size_t height);
        uint32_t createColorPixel(uint8_t red, uint8_t green, uint8_t blue);
        void fillBuffer(uint32_t colorPixel);
};

#endif // BUFFER_H_
