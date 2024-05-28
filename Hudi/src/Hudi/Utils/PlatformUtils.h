#pragma once

#include <string>
#include <filesystem>

namespace Hudi {

	namespace FileDialogs {

		std::filesystem::path OpenFile(const char* filter);
		std::filesystem::path SaveFile(const char* filter);

	}

}