# Set path of vcpkg_installed folder
if(CMAKE_BUILD_TYPE STREQUAL "Release")
    set(VCPKG_INSTALLED_PATH "target/release/vcpkg_installed")
else()
    set(VCPKG_INSTALLED_PATH "build/vcpkg_installed")
endif()

if(APPLE)
    set(VCPKG_ROOT "${VCPKG_INSTALLED_PATH}/arm64-osx/lib")
    set(VCPKG_PATH "/opt/vcpkg")
endif()

set(CMAKE_TOOLCHAIN_FILE "${VCPKG_PATH}/scripts/buildsystems/vcpkg.cmake")
set(VCPKG_ROOT "${VCPKG_PATH}")

message("VCPKG_ROOT ${VCPKG_ROOT}   ${CMAKE_TOOLCHAIN_FILE}")