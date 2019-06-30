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

    inline Numeric(bool isSigned, uint64_t width) noexcept : isSigned(isSigned), width(width) {}

protected:
    inline ~Numeric() noexcept override = 0;
};

inline Node::Type::Numeric::~Numeric() noexcept = default;

}
