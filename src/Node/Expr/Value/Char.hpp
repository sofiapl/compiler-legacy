#pragma once

#include <Node/Expr/Value_.hpp>
#include <Node/Type/Numeric/Integer.hpp>

#include <llvm/ADT/APInt.h>

namespace Node {

namespace Expr {

namespace Value {

class Char: public Value_<Type::Numeric::Integer, llvm::APInt> {

public:
    Char(llvm::APInt * value):
            Value_ <Type::Numeric::Integer, V> (
                new Type::Numeric::Integer(),
                value
            )
    {
        type->_signed = false;
        type->bits = 16;
    }
};

}

}

}
