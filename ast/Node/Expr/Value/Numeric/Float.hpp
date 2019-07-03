#pragma once

#include <llvm/ADT/APFloat.h>

#include "../Numeric.hpp"

namespace ast {

class Node::Expr::Value::Numeric::Float : public Numeric {

public:
    const llvm::APFloat value;

    inline explicit Float(llvm::APFloat && value) noexcept : value(std::move(value)) {}

protected:
    inline ~Float() noexcept override = default;
};

}
