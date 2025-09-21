# Raylib + Vulkan Example

윈도우 관리와 입력 처리는 **Raylib**,  
렌더링은 **Vulkan**,  
ECS(Entity Component System)는 **EnTT** 로 구현한 예제 프로젝트입니다.  

---

## 📌 프로젝트 특징
- **Raylib**: 창 생성, 입력 처리, 사운드 관리  
- **Vulkan**: 렌더링 직접 구현 (OpenGL 미사용)  
- **EnTT**: ECS 구조 적용  
- **CMake FetchContent** 로 EnTT, Raylib 자동 다운로드  

---

## ⚙️ 빌드 요구사항
- CMake 3.14 이상
- C++17 이상 지원 컴파일러 (MSVC, clang, gcc 등)
- [Vulkan SDK](https://vulkan.lunarg.com/sdk/home) 설치 (예: `C:/VulkanSDK/1.4.321.1`)
- Git (FetchContent 사용)

---

## 🛠️ 빌드 방법
```bash
# 저장소 클론
git clone https://github.com/Rhw0213/entt-test
cd raylib-vulkan-example

# 빌드
cmake -B build
cmake --build build
