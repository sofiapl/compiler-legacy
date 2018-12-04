#pragma once

#include "../Expr_.hpp"
#include "../Identifier.hpp"
#include "../Type_.hpp"
#include "../Stmt_.hpp"

namespace Node {

namespace Stmt {

class VariableDefine: public Stmt_ {

public:
    Identifier * name  = nullptr;
    Type_      * type  = nullptr;
    Expr_      * value = nullptr;

    VariableDefine(Identifier * name, Expr_ * value) noexcept:
            name(name), value(value)
    {}

    VariableDefine(Identifier * name, Type_ * type) noexcept:
            name(name), type(type)
    {}

    VariableDefine(Identifier * name, Type_ * type, Expr_ * value) noexcept:
            name(name), type(type), value(value)
    {}
};

}

}
