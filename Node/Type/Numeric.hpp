#pragma once

#include "../Type_.hpp"
#include "../Expr_.hpp"

namespace Node {

namespace Type {

class Numeric: public Type_ {

public:
    bool          signed_ = true;
    unsigned char bits    = 32;
    bool          integer = true;

    bool canBeCasted(Type_ * _to) noexcept override {
        if (auto to = dynamic_cast<Numeric *>(_to)) {
            return true; // TODO
        }

        return false;
    }

    Expr_ * cast(Expr_ * expr) noexcept {
        return expr; // TODO
    }
};

}

}
