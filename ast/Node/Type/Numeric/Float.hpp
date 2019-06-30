#pragma once

#include "../Numeric.hpp"

namespace ast {

class Node::Type::Numeric::Float : public Numeric {

public:
    inline Float(bool isSigned, uint64_t width) noexcept : Numeric(isSigned, width) {}

protected:
    inline ~Float() noexcept override = default;
};

}
