#pragma once

#include "../Node.hpp"

namespace ast {

class Node::Stmt : public Node {

public:
    class VariableDefine;
    class Expression;
    class Return;

    inline Stmt() noexcept = default;

protected:
    inline ~Stmt() noexcept override = 0;
};

inline Node::Stmt::~Stmt() noexcept = default;

}
