#pragma once

#include <string>
#include <fstream>
#include <fmt/color.h>
#include <uni_algo/conv.h>

std::u32string get_data_of_utf8_file_into_u32string(std::string path);
