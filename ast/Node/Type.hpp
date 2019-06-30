#pragma once

#include "../Node.hpp"

namespace ast {

class Node::Type : public Node {

public:
    class Array;
    class Numeric;
    class Function;

    inline Type() noexcept = default;

protected:
    inline ~Type() noexcept override = 0;
};

inline Node::Type::~Type() noexcept = default;

}
