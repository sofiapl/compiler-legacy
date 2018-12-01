#pragma once

#include "../Expr_.hpp"
#include "../Stmt_.hpp"

namespace Node {

namespace Stmt {

class Return: public Stmt_ {

public:
    Expr_ * value = nullptr;

    explicit Return(Expr_ * value) noexcept: value(value) {}
};

}

}
