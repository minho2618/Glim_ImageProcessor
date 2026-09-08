/**
 * @file GrayscaleFilter.cpp
 */

#include "GrayscaleFilter.h"
#include "ImageBuffer.h"

#include <iostream>

namespace ip {

void GrayscaleFilter::apply(ImageBuffer& image) {
    for (int i = 0; i < image.dataSize(); i+=3) {
        // RGB 가중치 공식 적용
        int gray = (114 * static_cast<int>(image.data()[i]) + 587 * static_cast<int>(image.data()[i+1]) + 299 * static_cast<int>(image.data()[i+2])) / 1000;
        image.data()[i] = gray;
        image.data()[i + 1] = gray;
        image.data()[i + 2] = gray;
    }
}
}