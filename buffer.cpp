#include "buffer.hpp"
#include <cstddef>
#include <cstdint>

Buffer::Buffer(std::size_t width, std::size_t height) : width(width), height(height) {
    data = new uint32_t[width * height];

    uint32_t fillColorPixel = createColorPixel(12, 34, 100);
    fillBuffer(fillColorPixel);
}

Buffer::~Buffer() {
    delete data;
}

uint32_t Buffer::createColorPixel(uint8_t red, uint8_t green, uint8_t blue) {
    uint8_t alpha = 255;
    return (red << 24) | (green << 16) | (blue << 8) | alpha;
}

void Buffer::fillBuffer(uint32_t colorPixel) {

    for(size_t i = 0; i < sizeof(&data)/sizeof(uint32_t); ++i) {
        data[i] = colorPixel;
    }
}
