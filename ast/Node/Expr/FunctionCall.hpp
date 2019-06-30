#pragma once

#include <vector>

#include "../Expr.hpp"

namespace ast {

class Node::Expr::FunctionCall : public Expr {

public:
    const Node::Expr * const function;
    const std::vector<const Node::Expr *> arguments;

    inline FunctionCall(const Node::Expr * function, std::vector<const Node::Expr *> arguments) noexcept :
        function(function), arguments(std::move(arguments)) {}

protected:
    inline ~FunctionCall() noexcept override = default;
};

}
