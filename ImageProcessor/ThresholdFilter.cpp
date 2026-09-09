/*
* @file ThresholdFilter.cpp
*/

#include "ThresholdFilter.h"

#include "ImageBuffer.h"
#include "GrayscaleFilter.h"

namespace ip {
void ThresholdFilter::apply(ImageBuffer& image) {
	if (threshold < 0) {
		// 에러 반환
	}
	ip::GrayscaleFilter grayFilter;
	grayFilter.apply(image);

	for (int i = 0; i < image.dataSize(); i += 3) {
		int value = 0;
		if (image.data()[i] > threshold)
			value = 255;

		image.data()[i] = value;
		image.data()[i + 1] = value;
		image.data()[i + 2] = value;
	}
}
}