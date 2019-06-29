#pragma once

#include "../Stmt.hpp"

namespace ast {

class Node::Stmt::Expression : public Stmt {

public:
    const Node::Expr * const expression;

    explicit Expression(Expr * expression) noexcept : expression(expression) {}

protected:
    ~Expression() noexcept override = default;
};

}
