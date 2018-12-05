cmake_minimum_required(VERSION 3.12)
project(sofia)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR})

add_compile_options(
    -Wall
    -fkeep-inline-functions
    -O0
    -I${CMAKE_CURRENT_SOURCE_DIR}
)

find_package(Flex  REQUIRED)
find_package(Bison REQUIRED)

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
)

add_executable(
        sofia

        main.cpp

        # AST
        Node_.hpp
        Node/Identifier.hpp
        Node/Type_.hpp
        Node/Type/Numeric.hpp
        Node/Expr_.hpp
        Node/Stmt_.hpp
        Node/Stmt/VariableDefine.hpp
        Node/Stmt/Expression.hpp
        Node/Stmt/Return.hpp

        # Parser
        bridges.cpp
        ${CMAKE_CURRENT_BINARY_DIR}/lex.yy.c
        ${CMAKE_CURRENT_BINARY_DIR}/y.tab.c
        ${CMAKE_CURRENT_BINARY_DIR}/y.tab.h
)
