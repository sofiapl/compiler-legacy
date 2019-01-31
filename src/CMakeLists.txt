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

add_executable(sofia
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
        ${CMAKE_CURRENT_BINARY_DIR}/lex.yy.c
        ${CMAKE_CURRENT_BINARY_DIR}/y.tab.c
        ${CMAKE_CURRENT_BINARY_DIR}/y.tab.h
        bridges.cpp
        bridges.h
        Parser_.hpp
        Parser/Numeric_.hpp
        Parser/Numeric/Integer.cpp
        Parser/Numeric/Integer.hpp
        Parser/Numeric/Float.cpp
        Parser/Numeric/Float.hpp
)

target_include_directories(sofia PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_compile_features(sofia PUBLIC cxx_std_14)
target_compile_options(sofia PRIVATE
        -Wall -fkeep-inline-functions
        -O0 -g
)

target_include_directories(sofia PRIVATE ${LLVM_INCLUDE_DIRS})
target_compile_definitions(sofia PUBLIC  ${LLVM_DEFINITIONS})

llvm_map_components_to_libnames(llvm_libs support core irreader)
target_link_libraries(sofia ${llvm_libs})
