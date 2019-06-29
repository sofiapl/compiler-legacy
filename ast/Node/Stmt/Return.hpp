#pragma once

#include "../Stmt.hpp"

namespace ast {

class Node::Stmt::Return : public Stmt {

public:
    const Node::Expr * const value;

    explicit Return(Expr * value) noexcept : value(value) {}

protected:
    ~Return() noexcept override = default;
};

}
