#pragma once

#include <cstdint>

#include "../Value.hpp"

namespace ast {

class Node::Expr::Value::Character : public Value {

public:
    const int8_t bytes[2];

    inline explicit Character(const int8_t bytes[2]) noexcept : bytes {bytes[0], bytes[1]} {}

protected:
    inline ~Character() noexcept override = default;
};

}
