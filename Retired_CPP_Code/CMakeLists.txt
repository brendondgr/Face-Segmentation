cmake_minimum_required(VERSION 3.16)
project(application VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "..")

# Store the environment variable in a CMake variable
set(INCLUDE_DIR "$ENV{cpp_libs}")

# Include Specific Directories in cpp_libs
include_directories("${INCLUDE_DIR}/json/include")

# Collect all the source files
file(GLOB SOURCES "*.cpp" "*.h")

find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets)

qt_standard_project_setup()

qt_add_executable(application main.cpp definition.cpp)

target_link_libraries(application PRIVATE 
    Qt6::Core 
    Qt6::Gui 
    Qt6::Widgets
)