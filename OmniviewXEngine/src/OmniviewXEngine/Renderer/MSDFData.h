#ifndef _MSDFDATA_H_
#define _MSDFDATA_H_

#include <vector>

#include "msdf-atlas-gen/msdf-atlas-gen.h"

namespace OmniviewXEngine
{
    struct MSDFData
	{
		std::vector<msdf_atlas::GlyphGeometry> Glyphs;
		msdf_atlas::FontGeometry FontGeometry;
	};
}

#endif