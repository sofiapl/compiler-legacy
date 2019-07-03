#pragma once

#include "../Type.hpp"

namespace ast {

class Node::Type::Character : public Type {

public:
    inline Character() noexcept = default;

protected:
    inline ~Character() noexcept override = default;
};

}
