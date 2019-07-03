#pragma once

#include <vector>

#include "../Expr.hpp"
#include "Function/Argument.hpp"

namespace ast {

class Node::Expr::SingleExprFunction : public Expr {

public:
    typedef Node::Expr::Function::Argument Argument;

    const std::vector<const Argument *> arguments;
    const Node::Expr * const expression;
    const Node::Type * const returnType;

    inline explicit SingleExprFunction(std::vector<const Argument *> && arguments, const Node::Expr * expression, const Node::Type * returnType) noexcept :
        arguments(std::move(arguments)), expression(expression), returnType(returnType) {}

protected:
    inline ~SingleExprFunction() noexcept override = default;
};

}
