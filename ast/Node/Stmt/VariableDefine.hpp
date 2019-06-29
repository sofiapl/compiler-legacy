#pragma once

#include <string>

#include "../Stmt.hpp"

namespace ast {

class Node::Stmt::VariableDefine : public Stmt {

public:
    const std::string * const name;

    const Node::Type * const type;
    const Node::Expr * const value;

    VariableDefine(std::string * name, Node::Type * type, Node::Expr * value) noexcept : name(name), type(type), value(value) {}

protected:
    ~VariableDefine() noexcept override = default;
};

}
