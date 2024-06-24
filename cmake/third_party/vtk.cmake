# ---- Include MPI ----

include(cmake/third_party/mpi.cmake)

# ---- Include VTK ----

set(VTK_INCLUDE_DIR "${VCPKG_INSTALLED_PATH}/${TRIPLET}/include/vtk-9.3")
include_directories(${VTK_INCLUDE_DIR})

find_package(VTK REQUIRED COMPONENTS
    CommonColor
    CommonCore
    CommonDataModel
    FiltersStatistics
    IOGeometry
    RenderingCore
    RenderingOpenGL2
    RenderingAnnotation
    FiltersSources
    CommonTransforms
    FiltersCore
    FiltersExtraction
    FiltersGeometry
    FiltersModeling
    FiltersVerdict
    InteractionWidgets
    InteractionStyle
)

if (NOT VTK_FOUND)
  message(FATAL_ERROR "Unable to find the VTK build folder.")
endif()

target_link_libraries(qtvtk PRIVATE ${VTK_LIBRARIES})

# vtk_module_autoinit is needed
vtk_module_autoinit(
  TARGETS qtvtk
  MODULES ${VTK_LIBRARIES}
)
