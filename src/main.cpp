//#include "main.h"
#include <raylib.h>
#include <vulkan/vulkan.h>

VkInstance instance;
VkSurfaceKHR surface;
VkPhysicalDevice physicalDevice = VK_NULL_HANDLE;
VkDevice device;
VkQueue graphicsQueue;

void CheckVk(VkResult result, const char* msg) {
    if (result != VK_SUCCESS) {
        throw std::runtime_error(msg);
    }
}

void InitVulkan(void* windowHandle) {
    // 1. Instance 생성
    VkApplicationInfo appInfo{};
    appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
    appInfo.pApplicationName = "Raylib + Vulkan Example";
    appInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
    appInfo.apiVersion = VK_API_VERSION_1_2;

    VkInstanceCreateInfo createInfo{};
    createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
    createInfo.pApplicationInfo = &appInfo;

    CheckVk(vkCreateInstance(&createInfo, nullptr, &instance), "Failed to create Vulkan instance!");

    // 2. Surface (Windows)
#ifdef _WIN32
    HWND hwnd = (HWND)windowHandle;
    HINSTANCE hinstance = GetModuleHandle(nullptr);

    VkWin32SurfaceCreateInfoKHR surfaceInfo{};

    surfaceInfo.sType = VK_STRUCTURE_TYPE_WIN32_SURFACE_CREATE_INFO_KHR;
    surfaceInfo.hwnd = hwnd;
    surfaceInfo.hinstance = hinstance;

    CheckVk(vkCreateWin32SurfaceKHR(instance, &surfaceInfo, nullptr, &surface),
        "Failed to create Win32 surface!");
#endif

    // 3. Physical Device 선택
    uint32_t deviceCount = 0;
    vkEnumeratePhysicalDevices(instance, &deviceCount, nullptr);
    if (deviceCount == 0) throw std::runtime_error("No Vulkan-compatible GPU found!");

    std::vector<VkPhysicalDevice> devices(deviceCount);
    vkEnumeratePhysicalDevices(instance, &deviceCount, devices.data());
    physicalDevice = devices[0];

    // 4. Logical Device + Queue (가장 단순화)
    float priority = 1.0f;
    VkDeviceQueueCreateInfo queueCreateInfo{};
    queueCreateInfo.sType = VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO;
    queueCreateInfo.queueFamilyIndex = 0; // 실제로는 Queue Family 검색 필요
    queueCreateInfo.queueCount = 1;
    queueCreateInfo.pQueuePriorities = &priority;

    VkDeviceCreateInfo deviceInfo{};
    deviceInfo.sType = VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO;
    deviceInfo.queueCreateInfoCount = 1;
    deviceInfo.pQueueCreateInfos = &queueCreateInfo;

    CheckVk(vkCreateDevice(physicalDevice, &deviceInfo, nullptr, &device), "Failed to create device!");
    vkGetDeviceQueue(device, 0, 0, &graphicsQueue);
}

void CleanupVulkan() {
    if (device) vkDestroyDevice(device, nullptr);
    if (surface) vkDestroySurfaceKHR(instance, surface, nullptr);
    if (instance) vkDestroyInstance(instance, nullptr);
}

int main() {
    int screenWidth = 800;
    int screenHeight = 600;

    // raylib 창 (OpenGL 렌더링 없음)
    InitWindow(screenWidth, screenHeight, "Raylib + Vulkan Example (No OpenGL)");

    try {
        void* handle = GetWindowHandle();
        InitVulkan(handle);

        while (!WindowShouldClose()) {
            // 여기서 Vulkan 스왑체인/렌더패스 초기화 후 화면 클리어 가능
            // (지금은 설치/환경 확인용 루프)
        }

        CleanupVulkan();
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        CloseWindow();
        return -1;
    }

    CloseWindow();
    return 0;
}
