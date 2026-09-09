/**
 * @file ContrastFilter.cpp
 */

#include "ContrastFilter.h"
#include "ImageBuffer.h"

#include <iostream>

namespace ip {
    void ContrastFilter::apply(ImageBuffer& image) {
        for (int i = 0; i < image.dataSize(); i++) {
            int value = 128 + (image.data()[i] - 128) * contrast;
            if (value > 255)
                value = 255;
            if (value < 0)
                value = 0;

            image.data()[i] = value;
        }
    }
}