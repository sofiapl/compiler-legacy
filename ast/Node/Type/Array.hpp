#pragma once

#include <cstdint>

#include "../Type.hpp"

namespace ast {

class Node::Type::Array : public Type {

public:
    const Node::Type * const type;
    const uint64_t * const length;

    inline Array(const Node::Type * type, const uint64_t * length) noexcept : type(type), length(length) {}

protected:
    inline ~Array() noexcept override = default;
};

}
