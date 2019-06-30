cmake_minimum_required(VERSION 3.12)

project(sofia)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH};${CMAKE_CURRENT_SOURCE_DIR}/cmake)

# find_package(Flex  REQUIRED)
# find_package(Bison REQUIRED)

find_package(LLVM REQUIRED CONFIG)
message(STATUS "Found LLVM ${LLVM_PACKAGE_VERSION}")
message(STATUS "Using LLVMConfig.cmake in: ${LLVM_DIR}")

add_executable(
        sofia

        main.cpp
)

add_subdirectory(ast)
target_link_libraries(sofia sofia_ast)

target_compile_features(sofia PUBLIC cxx_std_14)
target_compile_options(sofia PRIVATE
        -Wall -fkeep-inline-functions
        -O0 -g
)

target_include_directories(sofia PRIVATE ${LLVM_INCLUDE_DIRS})
target_compile_definitions(sofia PUBLIC  ${LLVM_DEFINITIONS})

llvm_map_components_to_libnames(llvm_libs support core irreader)
target_link_libraries(sofia ${llvm_libs})
