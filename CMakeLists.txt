cmake_minimum_required(VERSION 3.0)
project(Example)
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmakeModules")

set(CMAKE_CXX_STANDARD 11)

# setup ROOT includes and libraries
message(STATUS "")
message(STATUS ">>> Setting up ROOT.")
find_package(ROOT 5.34.04 REQUIRED)
include_directories(${ROOT_INCLUDE_DIR})

# Source files
set(EXAMPLE_A_SOURCE_FILES ExampleA.cc src/exampleA/Detector.cc src/exampleA/Hit.cc src/exampleA/Track.cc)
set(EXAMPLE_B_SOURCE_FILES ExampleB.cc src/exampleB/ )

# Own includes
include_directories(include/)
include_directories(include/exampleA/)
include_directories(include/exampleB/)

# Executable
message(STATUS "")
add_executable(ExampleA ${EXAMPLE_A_SOURCE_FILES})
add_executable(ExampleB ${EXAMPLE_B_SOURCE_FILES})

# Linking: here against ROOT
target_link_libraries(ExampleA ${ROOT_LIBS})

target_link_libraries(ExampleB ${ROOT_LIBS})

