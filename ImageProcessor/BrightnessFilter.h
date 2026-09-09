#pragma once

/**
 * @file BrightnessFilter.h
 */

#include "ImageBuffer.h"
#include "FilterBase.h"

namespace ip {
	class BrightnessFilter : public FilterBase {
	public:
		BrightnessFilter() = default;
		BrightnessFilter(int value) : brightness(value) {}

		void apply(ImageBuffer& image) override;

	private:
		int brightness = 0;
	};
} // namespace ip
