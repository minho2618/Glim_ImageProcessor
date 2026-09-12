#pragma once

/**
 * @file ConvolutionFilter.h
 */

#include "ImageBuffer.h"
#include "FilterBase.h"
#include <array>

namespace ip {
	class ConvolutionFilter : public FilterBase {
	public:
		using Kernel = std::array<std::array<double, 3>, 3>;

		ConvolutionFilter() = default;
		ConvolutionFilter(const Kernel& kernel) : _kernel(kernel) {}

		void apply(ImageBuffer& image) override;
	private:
		// 어떤 필터(커널)을 적용할 것인지
		Kernel _kernel;
	};
} // namespace ip