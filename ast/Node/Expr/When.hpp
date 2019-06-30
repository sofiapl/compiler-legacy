#pragma once

#include <vector>

#include "../Expr.hpp"

namespace ast {

class Node::Expr::When : public Expr {

public:
    class Case;

    const Node::Expr * const expression;
    const std::vector<const Case *> cases;

    inline When(const Node::Expr * expression, std::vector<const Case *> && cases) noexcept :
        expression(expression), cases(std::move(cases)) {}

protected:
    inline ~When() noexcept override = default;
};

}
