cmake_minimum_required(VERSION 3.12)

project(sofia)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH};${CMAKE_CURRENT_SOURCE_DIR}/cmake)

find_package(LLVM REQUIRED CONFIG)
message(STATUS "Found LLVM ${LLVM_PACKAGE_VERSION}")
message(STATUS "Using LLVMConfig.cmake in: ${LLVM_DIR}")

add_library(
        sofia_ast STATIC

        ast.cpp
        ast.hpp
        Node.hpp
        Node/Expr.hpp
        Node/Expr/When.hpp
        Node/Expr/When/Case.hpp
        Node/Expr/Value.hpp
        Node/Expr/Value/Numeric.hpp
        Node/Expr/Value/Numeric/Float.hpp
        Node/Expr/Value/Numeric/Integer.hpp
        Node/Expr/Value/Character.hpp
        Node/Expr/Value/String.hpp
        Node/Expr/Function.hpp
        Node/Expr/Function/Argument.hpp
        Node/Expr/SingleExprFunction.hpp
        Node/Expr/FunctionCall.hpp
        Node/Expr/ElementFetch.hpp
        Node/Expr/VariableFetch.hpp
        Node/Expr/UnaryOperator.hpp
        Node/Expr/BinaryOperator.hpp
        Node/Stmt.hpp
        Node/Stmt/Return.hpp
        Node/Stmt/Expression.hpp
        Node/Stmt/VariableDefine.hpp
        Node/Type.hpp
        Node/Type/Array.hpp
        Node/Type/Numeric.hpp
        Node/Type/Numeric/Float.hpp
        Node/Type/Numeric/Integer.hpp
        Node/Type/Character.hpp
        Node/Type/Function.hpp
)

target_compile_features(sofia_ast PUBLIC cxx_std_14)
target_compile_options(sofia_ast PRIVATE
        -Wall -fkeep-inline-functions
        -O0 -g
)

target_include_directories(sofia_ast PRIVATE ${LLVM_INCLUDE_DIRS})
target_compile_definitions(sofia_ast PUBLIC  ${LLVM_DEFINITIONS})

llvm_map_components_to_libnames(llvm_libs support core irreader)
target_link_libraries(sofia_ast ${llvm_libs})
