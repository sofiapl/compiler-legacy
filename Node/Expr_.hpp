#pragma once

#include "../Node_.hpp"

namespace Node {

class Type_;

class Expr_: public Node_ {

public:
    virtual Type_ * type() = 0;
};

}
