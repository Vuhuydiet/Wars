#pragma once

#include <iostream>
#include <fstream>
#include <memory>
#include <algorithm>
#include <functional>
#include <initializer_list>
#include <future>
#include <chrono>
#include <ctime>
#include <cmath>
#include <typeinfo>
#include <sstream>

#include <array>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
#include <bitset>

#include "Hudi/Core/Log.h"
#include "Hudi/Core/Core.h"

#include "Hudi/Math/Vec3.h"

#include "Hudi/Debug/Instrumentor.h"

#ifdef HD_PLATFORM_WINDOWS
	#include <Windows.h>
#endif