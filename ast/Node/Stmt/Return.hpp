#pragma once

#include "../Stmt.hpp"

namespace ast {

class Node::Stmt::Return : public Stmt {

public:
    const Node::Expr * const value;

    inline explicit Return(const Node::Expr * value) noexcept : value(value) {}

protected:
    inline ~Return() noexcept override = default;
};

}
