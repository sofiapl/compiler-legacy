#pragma once

#include "../Numeric.hpp"

namespace ast {

class Node::Type::Numeric::Integer : public Numeric {

public:
    inline Integer(bool isSigned, uint64_t width) noexcept : Numeric(isSigned, width) {}

protected:
    inline ~Integer() noexcept override = default;
};

}
