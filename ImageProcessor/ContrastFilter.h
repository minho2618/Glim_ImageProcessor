#pragma once

/**
 * @file ContrastFilter.h
 */

#include "ImageBuffer.h"
#include "FilterBase.h"

namespace ip {
	class ContrastFilter : public FilterBase {
	public:
		ContrastFilter() = default;
		ContrastFilter(int value) : contrast(value) {}

		void apply(ImageBuffer& image) override;

	private:
		int contrast = 0.5;
	};
} // namespace ip
