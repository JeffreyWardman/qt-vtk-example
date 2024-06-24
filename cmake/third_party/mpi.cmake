# ---- Include MPI ----

enable_language(C)

if(APPLE)
    # Manually set MPI paths
    set(MPI_LIBRARY_PATH /opt/vcpkg/packages/openmpi_arm64-osx/lib)
    set(MPI_INCLUDE_PATH /opt/vcpkg/packages/openmpi_arm64-osx/include)

    # Add the include directories
    include_directories(${MPI_INCLUDE_PATH})
    link_directories(${MPI_LIBRARY_PATH})

    set(MPI_C_COMPILER "/opt/vcpkg/packages/openmpi_arm64-osx/tools/openmpi/bin/mpicc")
    set(MPI_CXX_COMPILER "/opt/vcpkg/packages/openmpi_arm64-osx/tools/openmpi/bin/mpic++")
endif()

find_package(MPI REQUIRED)

if(MPI_FOUND)
    message(STATUS "MPI found")
    set(CMAKE_CXX_COMPILER ${MPI_CXX_COMPILER})
    set(CMAKE_C_COMPILER ${MPI_C_COMPILER})
    include_directories(SYSTEM ${MPI_INCLUDE_PATH})
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${MPI_CXX_COMPILE_FLAGS}")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${MPI_CXX_LINK_FLAGS}")

    message(STATUS "MPI_INCLUDE_PATH: ${MPI_INCLUDE_PATH}")
    message(STATUS "MPI_LIBRARIES: ${MPI_LIBRARIES}")
    message(STATUS "MPIEXEC: ${MPIEXEC}")
else()
    message(FATAL_ERROR "MPI not found")
endif()

target_link_libraries(qtvtk PRIVATE ${MPI_LIBRARIES})
