#pragma once

#include "../Node.hpp"

namespace ast {

class Node::Stmt : public Node {

public:
    class VariableDefine;
    class Expression;
    class Return;

    Stmt() noexcept = default;

protected:
    ~Stmt() noexcept override = 0;
};

}
