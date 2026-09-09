#pragma once

/**
 * @file ThresholdFilter.h
 */

#include "ImageBuffer.h"
#include "FilterBase.h"

namespace ip {
	class ThresholdFilter : public FilterBase {
	public:
		ThresholdFilter() = default;
		ThresholdFilter(int value) : threshold(value) {}

		void apply(ImageBuffer& image) override;

	private:
		int threshold;
	};
} // namespace ip