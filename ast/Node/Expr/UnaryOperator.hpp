#pragma once

#include "../Expr.hpp"

namespace ast {

class Node::Expr::UnaryOperator : public Expr {

public:
    // TODO

    const Node::Expr * const operand;

    inline explicit UnaryOperator(const Node::Expr * operand) noexcept : operand(operand) {}

protected:
    inline ~UnaryOperator() noexcept override = 0;
};

inline Node::Expr::UnaryOperator::~UnaryOperator() noexcept = default;

}
