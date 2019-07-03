#pragma once

#include <string>

#include "../Value.hpp"

namespace ast {

class Node::Expr::Value::String : public Value {

public:
    const std::string value;

    inline explicit String(std::string && value) noexcept : value(std::move(value)) {}

protected:
    inline ~String() noexcept override = default;
};

}
