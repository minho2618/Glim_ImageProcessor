/**
 * @file BrightnessFilter.cpp
 */

#include "BrightnessFilter.h"
#include "ImageBuffer.h"

#include <iostream>

namespace ip {

    void BrightnessFilter::apply(ImageBuffer& image) {
        if (brightness < 0 || brightness > 255) {
            // 에러처리
        }

        for (int i = 0; i < image.dataSize(); i++) {           
            if (image.data()[i] + brightness > 255)
                image.data()[i] = 255;
            else if (image.data()[i] + brightness < 0)
                image.data()[i] = 0;
            else
                image.data()[i] = image.data()[i] + brightness;
        }
    }
}