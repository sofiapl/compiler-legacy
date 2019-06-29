add_library(
        ast STATIC

        Node.cpp
        Node.hpp
        Node/Expr.cpp
        Node/Expr.hpp
        Node/Stmt.cpp
        Node/Stmt.hpp
        Node/Stmt/VariableDefine.hpp
        Node/Stmt/Expression.hpp
        Node/Stmt/Return.hpp

        Node/Type.cpp
        Node/Type.hpp
        Node/Type/Array.hpp
        Node/Type/Numeric.cpp
        Node/Type/Numeric.hpp
        Node/Type/Numeric/Float.hpp
        Node/Type/Numeric/Integer.hpp

        Node/Type/Function.hpp
)