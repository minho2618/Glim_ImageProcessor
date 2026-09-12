/**
 * @file ConvolutionFilter.cpp
 */

#include "ConvolutionFilter.h"
#include "ImageBuffer.h"

#include <iostream>
#include <array>
#include <algorithm>

namespace ip {

void ConvolutionFilter::apply(ImageBuffer& image) {
    int width = image.width();
    int height = image.height();
    int channels = 3;

    ImageBuffer original = image;

    for (int y = 1; y < height - 1; ++y) {
        for (int x = 1; x < width - 1; ++x) {

            for (int channel = 0; channel < channels; ++channel) {
                double sum = 0.0;

                for (int ky = -1; ky <= 1; ++ky) {
                    for (int kx = -1; kx <= 1; ++kx) {
                        const int pixelX = x + kx;
                        const int pixelY = y + ky;

                        const int index = (pixelY * width + pixelX) * channels + channel;

                        sum += original.data()[index] * _kernel[ky + 1][kx + 1];                        
                    }
                }

                int result = std::clamp(static_cast<int>(std::round(sum)), 0, 255);

                int outIndex = (y * width + x) * channels + channel;
                image.data()[outIndex] = static_cast<std::uint8_t>(result);
                
            }
        }
    }
}

}