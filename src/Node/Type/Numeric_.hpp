#pragma once

#include <Node/Type_.hpp>

namespace Node {

namespace Type {

class Numeric_: public Type_ {

public:
    typedef unsigned BitsType;

    static const bool     DEFAULT_SIGNED = true;
    static const BitsType DEFAULT_BITS   = 32;

    bool     _signed = DEFAULT_SIGNED;
    BitsType bits    = DEFAULT_BITS;
};

}

}
