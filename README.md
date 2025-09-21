# Raylib + Vulkan Example

윈도우 입력/창 관리는 **Raylib** 으로,
렌더링은 **Vulkan** 으로 직접 처리하는 예제 프로젝트입니다.

## 빌드 방법

### 요구사항
- CMake 3.14+
- C++17 지원 컴파일러
- Vulkan SDK (https://vulkan.lunarg.com/sdk/home)
- Git (FetchContent로 EnTT, Raylib 자동 다운로드)

### 빌드
```bash
git clone https://github.com/yourname/raylib-vulkan-example.git
cd raylib-vulkan-example
cmake -B build
cmake --build build