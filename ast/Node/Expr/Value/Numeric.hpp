#pragma once

#include "../Value.hpp"

namespace ast {

class Node::Expr::Value::Numeric : public Value {

public:
    class Float;
    class Integer;

    inline Numeric() noexcept = default;

protected:
    inline ~Numeric() noexcept override = 0;
};

inline Node::Expr::Value::Numeric::~Numeric() noexcept = default;

}
