#pragma once

#include "../Stmt.hpp"

namespace ast {

class Node::Stmt::Expression : public Stmt {

public:
    const Node::Expr * const expression;

    inline explicit Expression(const Node::Expr * expression) noexcept : expression(expression) {}

protected:
    inline ~Expression() noexcept override = default;
};

}
