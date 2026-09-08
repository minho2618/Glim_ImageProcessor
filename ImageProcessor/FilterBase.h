#pragma once

#include "ImageBuffer.h"

namespace ip {
class FilterBase {
public:
	virtual void apply(ImageBuffer& image) = 0;

	virtual ~FilterBase() = default;
};
}