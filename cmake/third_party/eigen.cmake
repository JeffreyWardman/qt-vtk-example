find_package(Eigen3 REQUIRED)
include_directories(${EIGEN3_INCLUDE_DIR})
target_link_libraries(qtvtk PRIVATE Eigen3::Eigen)