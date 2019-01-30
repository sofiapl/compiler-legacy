#pragma once

#include <Node/Expr_.hpp>

namespace Node {

namespace Expr {

template <class T, class V>
class Value_: public Expr_ {

public:
    typedef T TypeType;
    typedef V ValueType;

    Value_(T * type, V * value):
            type(type),
            value(value)
    {}

    T * type;
    V * value;
};

}

}