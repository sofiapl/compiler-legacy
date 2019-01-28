#pragma once

#include <Node/Expr/Value/Numeric_.hpp>
#include <Node/Type/Numeric/Float.hpp>

#include <llvm/ADT/APFloat.h>

namespace Node {

namespace Expr {

namespace Value {

namespace Numeric {

typedef Numeric_<Type::Numeric::Float, llvm::APFloat> Float;

}

}

}

}
