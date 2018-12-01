#pragma once

#include "Identifier.hpp"

namespace Node {

class Type: public Identifier {

public:
    Type() noexcept: Identifier() {}
    Type(const std::string & name) noexcept: Identifier(name) {}
};

}
