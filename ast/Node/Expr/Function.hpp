#pragma once

#include <vector>

#include "../Expr.hpp"

namespace ast {

class Node::Expr::Function : public Expr {

public:
    class Argument;

    const std::vector<const Argument *> arguments;
    const std::vector<const Node::Stmt *> body;
    const Node::Type * const returnType;

    inline explicit Function(std::vector<const Argument *> && arguments, std::vector<const Node::Stmt *> && body, const Node::Type * returnType) noexcept :
        arguments(std::move(arguments)), body(std::move(body)), returnType(returnType) {}

protected:
    inline ~Function() noexcept override = default;
};

}
