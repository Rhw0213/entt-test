
include(FetchContent)

# ----- EnTT -----
FetchContent_Declare(
    EnTT
    GIT_REPOSITORY https://github.com/skypjack/entt.git
    GIT_TAG v3.15.0
)
FetchContent_MakeAvailable(EnTT)

# ----- raylib -----
FetchContent_Declare(
    raylib 
    GIT_REPOSITORY https://github.com/raysan5/raylib.git
    GIT_TAG 5.5
)
set(SUPPORT_MODULE_RLGL OFF CACHE BOOL "" FORCE)
set(SUPPORT_MODULE_RTEXTURES OFF CACHE BOOL "" FORCE)
set(SUPPORT_MODULE_RMODELS OFF CACHE BOOL "" FORCE)
set(SUPPORT_MODULE_RSHADERS OFF CACHE BOOL "" FORCE)

set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(BUILD_GAMES OFF CACHE BOOL "" FORCE)
set(BUILD_SHARED_LIBS OFF CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(raylib)

target_include_directories(raylib PUBLIC ${CMAKE_SOURCE_DIR}/src/config/raylib_config)

# ----- Vulkan -----
set(Vulkan_INCLUDE_DIR "C:/VulkanSDK/1.4.321.1/Include")
set(Vulkan_LIBRARY "C:/VulkanSDK/1.4.321.1/Lib/vulkan-1.lib")
find_package(Vulkan REQUIRED)

