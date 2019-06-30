#pragma once

namespace ast {

class Node {

public:
    class Expr;
    class Stmt;
    class Type;

    inline Node() noexcept = default;

protected:
    inline virtual ~Node() noexcept = 0;
};

inline Node::~Node() noexcept = default;

}
