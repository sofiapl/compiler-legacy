#pragma once

#include <llvm/ADT/APInt.h>

#include "../Numeric.hpp"

namespace ast {

class Node::Expr::Value::Numeric::Integer : public Numeric {

public:
    const llvm::APInt value;

    inline explicit Integer(llvm::APInt && value) noexcept : value(std::move(value)) {}

protected:
    inline ~Integer() noexcept override = default;
};

}
