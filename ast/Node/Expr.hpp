#pragma once

#include "../Node.hpp"

namespace ast {

class Node::Expr : public Node {

public:
    class When;
    class Value;
    class Function;
    class FunctionCall;
    class ElementFetch;
    class VariableFetch;
    class UnaryOperator;
    class AssignOperator;
    class BinaryOperator;

    inline Expr() noexcept = default;

protected:
    inline ~Expr() noexcept override = 0;
};

inline Node::Expr::~Expr() noexcept = default;

}
