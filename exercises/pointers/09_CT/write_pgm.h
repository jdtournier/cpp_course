#pragma once

#include <string>
#include "terminal_graphics.h"

void write_pgm (const std::string& filename, const TG::Image<float>& out, float scale_factor);

