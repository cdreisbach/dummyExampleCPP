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
file(GLOB EXAMPLE_A_SOURCE  src/exampleA/*.cc)
file(GLOB EXAMPLE_A_HEADERS include/exampleA/*.h)

file(GLOB EXAMPLE_B_SOURCE  src/exampleB/*.cc)
file(GLOB EXAMPLE_B_HEADERS include/exampleB/*.h)


# Executable
message(STATUS "")
add_executable(ExampleA ExampleA.cc ${EXAMPLE_A_SOURCE} ${EXAMPLE_A_HEADERS})
add_executable(ExampleB ExampleB.cc ${EXAMPLE_B_SOURCE} ${EXAMPLE_B_HEADERS})

# Linking: here against ROOT
target_link_libraries(ExampleA ${ROOT_LIBS})
target_link_libraries(ExampleB ${ROOT_LIBS})

