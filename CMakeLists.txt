cmake_minimum_required(VERSION 3.12)
project(sofia)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR})

add_compile_options(
    -Wall
    -fkeep-inline-functions
    -O0
    -g
    -I${CMAKE_CURRENT_SOURCE_DIR}
)

find_package(Flex  REQUIRED)
find_package(Bison REQUIRED)
find_package(LLVM  REQUIRED CONFIG)

message(STATUS "Found LLVM ${LLVM_PACKAGE_VERSION}")
message(STATUS "Using LLVMConfig.cmake in: ${LLVM_DIR}")

add_custom_command(
        MAIN_DEPENDENCY "${CMAKE_CURRENT_SOURCE_DIR}/grammar.lex"
        PRE_BUILD
        COMMAND ${FLEX_EXECUTABLE}
        ARGS -o"${CMAKE_CURRENT_BINARY_DIR}/lex.yy.c" "${CMAKE_CURRENT_SOURCE_DIR}/grammar.lex"
        OUTPUT "${CMAKE_CURRENT_BINARY_DIR}/lex.yy.c"
)

add_custom_command(
        MAIN_DEPENDENCY "${CMAKE_CURRENT_SOURCE_DIR}/grammar.y"
        PRE_BUILD
        COMMAND ${BISON_EXECUTABLE}
        ARGS -y -d --debug --verbose -o"${CMAKE_CURRENT_BINARY_DIR}/y.tab.c"
        "${CMAKE_CURRENT_SOURCE_DIR}/grammar.y"
        DEPENDS "${CMAKE_CURRENT_BINARY_DIR}/lex.yy.c"
        OUTPUT "${CMAKE_CURRENT_BINARY_DIR}/y.tab.c"
        OUTPUT "${CMAKE_CURRENT_BINARY_DIR}/y.tab.h"
        OUTPUT "${CMAKE_CURRENT_BINARY_DIR}/y.output"
)

include_directories(${LLVM_INCLUDE_DIRS})
add_definitions(${LLVM_DEFINITIONS})

add_executable(
        sofia

        main.cpp

        # AST
        Node_.hpp
        Node/Expr_.hpp
        Node/Expr/Value_.hpp
        Node/Expr/Value/Numeric_.hpp
        Node/Expr/Value/Numeric/Float.hpp
        Node/Expr/Value/Numeric/Integer.hpp
        Node/Identifier.hpp
        Node/Stmt_.hpp
        Node/Stmt/Expression.hpp
        Node/Stmt/Return.hpp
        Node/Stmt/VariableDefine.hpp
        Node/Type_.hpp
        Node/Type/Numeric_.hpp
        Node/Type/Numeric/Float.hpp
        Node/Type/Numeric/Integer.hpp

        # Parser
        bridges.cpp
        bridges.h
        ${CMAKE_CURRENT_BINARY_DIR}/lex.yy.c
        ${CMAKE_CURRENT_BINARY_DIR}/y.tab.c
        ${CMAKE_CURRENT_BINARY_DIR}/y.tab.h
        Parser_.hpp
        Parser/Numeric_.hpp
        Parser/Numeric/Integer.hpp
        Parser/Numeric/Float.hpp
)

llvm_map_components_to_libnames(llvm_libs support core irreader)

target_link_libraries(sofia ${llvm_libs})
