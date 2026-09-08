#pragma once

/**
 * @file GrayscaleFilter.h
 */

#include "ImageBuffer.h"
#include "FilterBase.h"

namespace ip {
class GrayscaleFilter : public FilterBase {
public:
	void apply(ImageBuffer& image) override;
};
} // namespace ip