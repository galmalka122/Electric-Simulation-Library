cmake_minimum_required(VERSION 3.10)

project(Electric VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add include directory
include_directories(include)

# Add all source files
file(GLOB_RECURSE SOURCES "library.cpp" "src/*.cpp")

# Create the library
add_library(electric STATIC ${SOURCES})

# Specify include directories for the library
target_include_directories(electric PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
)

# Installation rules
install(TARGETS electric
        EXPORT ElectricTargets
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib
        RUNTIME DESTINATION bin
        INCLUDES DESTINATION include
)

install(DIRECTORY include/ DESTINATION include)

# Generate and install export file
install(EXPORT ElectricTargets
        FILE ElectricTargets.cmake
        NAMESPACE Electric::
        DESTINATION lib/cmake/Electric
)

# Generate the config file
include(CMakePackageConfigHelpers)
write_basic_package_version_file(
        "ElectricConfigVersion.cmake"
        VERSION ${PROJECT_VERSION}
        COMPATIBILITY SameMajorVersion
)

configure_package_config_file(
        "${CMAKE_CURRENT_SOURCE_DIR}/cmake/ElectricConfig.cmake.in"
        "${CMAKE_CURRENT_BINARY_DIR}/ElectricConfig.cmake"
        INSTALL_DESTINATION lib/cmake/Electric
)

# Install the config files
install(FILES
        "${CMAKE_CURRENT_BINARY_DIR}/ElectricConfig.cmake"
        "${CMAKE_CURRENT_BINARY_DIR}/ElectricConfigVersion.cmake"
        DESTINATION lib/cmake/Electric
)