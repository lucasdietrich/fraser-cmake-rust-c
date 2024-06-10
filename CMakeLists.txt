cmake_minimum_required(VERSION 3.0)
project(example)

add_executable(example src/main.c)

# Enable ExternalProject CMake module
include(ExternalProject)

# Set default ExternalProject root directory
set_directory_properties(PROPERTIES EP_PREFIX ${CMAKE_BINARY_DIR}/rust)

# Add rust_example
ExternalProject_Add(
    rust_example
    DOWNLOAD_COMMAND ""
    CONFIGURE_COMMAND ""
    BUILD_COMMAND cargo build COMMAND cargo build --release
    BINARY_DIR "${CMAKE_SOURCE_DIR}/common-rust"
    INSTALL_COMMAND ""
    LOG_BUILD ON)

# Create dependency of example on rust_example
add_dependencies(example rust_example)

# Specify example's link libraries
target_link_libraries(example
    debug "${CMAKE_SOURCE_DIR}/common-rust/target/debug/librust_example.a"
    optimized "${CMAKE_SOURCE_DIR}/common-rust/target/release/librust_example.a")

set_target_properties(example PROPERTIES C_STANDARD 99)
