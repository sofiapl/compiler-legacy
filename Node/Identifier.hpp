#pragma once

#include <string>

#include "../Node_.hpp"

namespace Node {

class Identifier: public Node_ {

public:
    Identifier() noexcept: Identifier("") {}

    explicit Identifier(const std::string & name) noexcept:
            _name(new std::string(name))
    {}

    ~Identifier() noexcept {
        delete _name;
    }

    std::string name() const noexcept {
        return std::string(* _name);
    }

    std::string & name() noexcept {
        return * _name;
    }

    void name(const std::string & name) noexcept {
        (* _name) = name;
    }

private:
    std::string * _name;
};

}
