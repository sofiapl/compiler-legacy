#pragma once

#include <Node/Expr/Value_.hpp>
#include <Node/Type/Numeric_.hpp>

namespace Node {

namespace Expr {

namespace Value {

template <class V>
using Numeric_ = Value_<Type::Numeric_, V>

}

}

}
