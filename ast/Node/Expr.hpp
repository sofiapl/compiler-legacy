#pragma once

#include "../Node.hpp"

namespace ast {

class Node::Expr : public Node {

public:
    // TODO

    Expr() noexcept = default;

protected:
    ~Expr() noexcept override = 0;
};

}
