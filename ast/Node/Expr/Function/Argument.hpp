#pragma once

#include <string>

#include "../Function.hpp"

namespace ast {

class Node::Expr::Function::Argument {

public:
    const std::string name;
    const Node::Type * const type;
    const Node::Expr * const defaultValue;

    inline Argument(std::string && name, const Node::Type * type, const Node::Expr * defaultValue) noexcept :
        name(std::move(name)), type(type), defaultValue(defaultValue) {}

protected:
    inline ~Argument() noexcept = default;
};

}
