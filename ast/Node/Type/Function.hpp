#pragma once

#include <vector>

#include "../Type.hpp"

namespace ast {

class Node::Type::Function : public Type {

public:
    const std::vector<const Node::Type *> arguments;
    const Node::Type * const returnType;

    inline Function(std::vector<const Node::Type *> && arguments, const Node::Type * returnType) noexcept :
        arguments(std::move(arguments)), returnType(returnType) {}

protected:
    inline ~Function() noexcept override = default;
};

}
