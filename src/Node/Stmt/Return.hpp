#pragma once

#include <Node/Expr_.hpp>
#include <Node/Stmt_.hpp>

namespace Node {

namespace Stmt {

class Return: public Stmt_ {

public:
    Expr_ * value = nullptr;

    explicit Return(Expr_ * value) noexcept:
            value(value)
    {}
};

}

}
