cmake_minimum_required(VERSION 3.22.1)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(APPLE)
    include_directories("/opt/homebrew/opt/m4/bin")
endif()

# ---- Declare VCPKG Environment ----

include(cmake/third_party/vcpkg.cmake)

# ---- Declare Additional Environments ----

if(APPLE)
    set(CMAKE_OSX_ARCHITECTURES "arm64")
    set(TRIPLET "arm64-osx")
    # Check if it's Apple Silicon (ARM-based Mac)
    # if(CMAKE_SYSTEM_PROCESSOR MATCHES "^arm")
    #     # Apple Silicon-specific
    #     set(TRIPLET "arm64-osx")
    #     set(CMAKE_OSX_ARCHITECTURES "arm64")
    # else()
    #     # Intel-based Mac (x86_64)
    #     set(TRIPLET "x64-osx")
    #     set(CMAKE_OSX_ARCHITECTURES "x86_64")
    # endif()
    set(CMAKE_BUILD_TOOL "Ninja")
    set(CMAKE_CXX_FLAGS "-Wall -Wextra")  # -Wpedantic")
else()
    # Handle other/unknown platforms if necessary
    message("Unknown platform detected")
endif()

set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g")
set(CMAKE_CXX_FLAGS_Release "${CMAKE_CXX_FLAGS_Release} -O3") # -G '${CMAKE_BUILD_TOOL}'")

project(
    qtvtk
    VERSION 0.0.0
    LANGUAGES CXX
)

# ---- Declare library ----

add_library(
    qtvtk STATIC
    src/qtvtk/render.cpp
)
target_include_directories(
    qtvtk ${warning_guard}
    PUBLIC
    "\$<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/src>"
)

include(cmake/third_party/eigen.cmake)
include(cmake/third_party/vtk.cmake)
target_compile_features(qtvtk PUBLIC cxx_std_20)

# ---- Declare executable ----

# Add QT path
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_PREFIX_PATH, qtvtk "/opt/homebrew/include")
find_package(Qt5 COMPONENTS Widgets REQUIRED)

qt5_wrap_ui(UI_HEADERS mainwindow.ui)

add_executable(qtvtk_exe
    src/main.cpp
    src/mainwindow.cpp
)
add_executable(qtvtk::exe ALIAS qtvtk_exe)
set_property(TARGET qtvtk_exe PROPERTY OUTPUT_NAME qtvtk_exe)
target_compile_features(qtvtk_exe PRIVATE cxx_std_20)
target_link_libraries(qtvtk_exe PRIVATE qtvtk Qt5::Widgets)
target_sources(qtvtk_exe PRIVATE ${UI_HEADERS})
