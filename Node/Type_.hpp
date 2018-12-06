#pragma once

#include "Identifier.hpp"

namespace Node {

class Type_: public Node_ {

public:
    virtual bool canBeCasted(Type_ * to) noexcept = 0;
    virtual Expr_ * cast(Expr_ * expr) noexcept = 0;
};

}
