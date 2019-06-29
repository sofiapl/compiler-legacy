#pragma once

#include "../Numeric.hpp"

namespace ast {

class Node::Type::Numeric::Float : public Numeric {

public:
    Float(bool isSigned, uint64_t width) noexcept : Numeric(isSigned, width) {}

protected:
    ~Float() noexcept override = default;
};

}
