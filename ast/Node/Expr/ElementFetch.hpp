#pragma once

#include "../Expr.hpp"

namespace ast {

class Node::Expr::ElementFetch : public Expr {

public:
    const Node::Expr * const container;
    const Node::Expr * const key;

    inline ElementFetch(const Node::Expr * container, const Node::Expr * key) noexcept :
        container(container), key(key) {}

protected:
    inline ~ElementFetch() noexcept override = default;
};

}
