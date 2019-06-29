#pragma once

#include <cstdint>

#include "../Type.hpp"

namespace ast {

class Node::Type::Numeric : public Type {

public:
    class Integer;
    class Float;

    const bool isSigned;
    const uint64_t width;

    Numeric(bool isSigned, uint64_t width) noexcept : isSigned(isSigned), width(width) {}

protected:
    ~Numeric() noexcept override = 0;
};

}
