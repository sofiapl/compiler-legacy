#pragma once

#include <vector>

#include "../Type.hpp"

namespace ast {

class Node::Type::Function : public Type {

public:
    const std::vector<Node::Type> arguments;
    const Node::Type * const returnType;

    Function(std::vector<Node::Type> && arguments, const Node::Type * returnType) noexcept :
        arguments(std::move(arguments)), returnType(returnType) {}

protected:
    ~Function() noexcept override = default;
};

}
