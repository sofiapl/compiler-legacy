#pragma once

#include <Node/Expr/Value/Numeric_.hpp>
#include <Node/Type/Numeric/Integer.hpp>

#include <llvm/ADT/APInt.h>

namespace Node {

namespace Expr {

namespace Value {

namespace Numeric {

typedef Numeric_<Type::Numeric::Integer, llvm::APInt> Integer;

}

}

}

}
