#pragma once

#include <string>

#include "../Expr.hpp"

namespace ast {

class Node::Expr::VariableFetch : public Expr {

public:
    const std::string name;

    inline explicit VariableFetch(std::string && name) noexcept :
        name(std::move(name)) {}

protected:
    inline ~VariableFetch() noexcept override = default;
};

}
