#pragma once

#include "../Node.hpp"

namespace ast {

class Node::Type : public Node {

public:
    class Array;
    class Numeric;
    class Function;

    Type() noexcept = default;

protected:
    ~Type() noexcept override = 0;
};

}
