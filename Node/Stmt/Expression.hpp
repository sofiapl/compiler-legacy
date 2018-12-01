#pragma once

#include "../Expr_.hpp"
#include "../Stmt_.hpp"

namespace Node {

namespace Stmt {

class Expression: public Stmt_ {

public:
    Expr_ * expr = nullptr;

    explicit Expression(Expr_ * expr) noexcept: expr(expr) {}
};

}

}
