#pragma once

#include "Identifier.hpp"

namespace Node {

class Type_: public Identifier {

public:
    Type_() noexcept: Identifier() {}
    explicit Type_(const std::string & name) noexcept: Identifier(name) {}

    virtual bool canBeCasted(Type_ * to) noexcept = 0;
    virtual Expr_ * cast(Expr_ * expr) noexcept = 0;
};

}
