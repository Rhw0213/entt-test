
#pragma once

#include <iostream>

#include <stdexcept>
#include <vector>
#include <cstring>
#ifdef _WIN32
	#define WIN32_LEAN_AND_MEAN
	#define NOGDI
	#define NOMINMAX
	#define NOUSER
	#define NODRAWTEXT
	#define NOHELP
	#include <windows.h>
#endif

#include <entt/entt.hpp>
#include <raylib.h>
#include <vulkan/vulkan.h>
