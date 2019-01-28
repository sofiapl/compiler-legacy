#pragma once

#include <Node/Expr/Value_.hpp>
#include <Node/Type/Numeric_.hpp>

namespace Node {

namespace Expr {

namespace Value {

template <class T, class V>
class Numeric_: public Value_<Type::Numeric_, V> {

public:
    typedef T TypeType;
    typedef V ValueType;

    typedef uint8_t RadixType;

    RadixType radix;

    Numeric_(T * type, V * value, RadixType radix):
            Value_ <Type::Numeric_, V> (type, value),
            radix(radix)
    {}
};

}

}

}
