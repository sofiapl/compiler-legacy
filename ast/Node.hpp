#pragma once

namespace ast {

class Node {

public:
    class Expr;
    class Stmt;
    class Type;

    Node() noexcept = default;

protected:
    virtual ~Node() noexcept = 0;
};

}
