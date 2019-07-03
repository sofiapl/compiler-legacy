#pragma once

#include "../Expr.hpp"

namespace ast {

class Node::Expr::BinaryOperator : public Expr {

public:
    // TODO

    const Node::Expr * const a;
    const Node::Expr * const b;

    inline BinaryOperator(const Node::Expr * a, const Node::Expr * b) noexcept : a(a), b(b) {}

protected:
    inline ~BinaryOperator() noexcept override = 0;
};

inline Node::Expr::BinaryOperator::~BinaryOperator() noexcept = default;

}
