#pragma once

#include "../Expr.hpp"

namespace ast {

class Node::Expr::Value : public Expr {

public:
    class Numeric;
    class Character;
    class String;

    inline Value() noexcept = default;

protected:
    inline ~Value() noexcept override = 0;
};

inline Node::Expr::Value::~Value() noexcept = default;

}
