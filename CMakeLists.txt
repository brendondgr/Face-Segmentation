cmake_minimum_required(VERSION 3.16)
project(application VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}) # This is to put the executable in the same directory as the source code
set(CMAKE_PREFIX_PATH $"{VCPKG_ROOT}installed/x64-windows/share/")

# Include directories for Header Files
# include_directories(${CMAKE_SOURCE_DIR})
# include_directories(include)

# Collect all the source files
file(GLOB SOURCES "*.cpp")

find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets)
find_package(jsoncpp CONFIG REQUIRED)

qt_standard_project_setup()

qt_add_executable(application main.cpp definition.cpp)

target_link_libraries(application PRIVATE 
    Qt6::Core 
    Qt6::Gui 
    Qt6::Widgets
    jsoncpp_lib
    # Qt6::Network 
    # Qt6::Qml 
    # Qt6::Quick 
    # Qt6::QuickWidgets
)