cmake_minimum_required(VERSION 3.20)

project(Project LANGUAGES CXX)


add_executable(Project
    Project.cpp
    BusinessLogic.cpp
    stdafx.cpp
    Project.rc
)

target_link_options(Project PRIVATE
    -static
    -static-libgcc
    -static-libstdc++
)

target_include_directories(Project PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
)

target_precompile_headers(Project PRIVATE stdafx.h)

target_compile_features(Project PRIVATE cxx_std_17)

target_compile_definitions(Project PRIVATE
    UNICODE
    _UNICODE
    _WIN32_WINNT=0x0A00
)

target_link_libraries(Project PRIVATE
    comctl32
    gdi32
    user32
    shell32
)

set_target_properties(Project PROPERTIES
    LINK_FLAGS "-Wl,-subsystem,console"
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)


add_custom_target(distclean
    COMMAND ${CMAKE_COMMAND} -E rm -rf
        ${CMAKE_BINARY_DIR}/CMakeFiles
        ${CMAKE_BINARY_DIR}/CMakeCache.txt
        ${CMAKE_BINARY_DIR}/cmake_install.cmake
        ${CMAKE_BINARY_DIR}/Makefile
        ${CMAKE_BINARY_DIR}/bin
    COMMENT "Removing all build artifacts and cache"
)
