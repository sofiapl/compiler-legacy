#pragma once

#include <string>

#include <Node_.hpp>

namespace Node {

class Identifier: public Node_ {

public:
    Identifier() noexcept: Identifier("") {}

    explicit Identifier(std::string && name) noexcept:
            _name(std::move(name))
    {}

    explicit Identifier(const std::string & name) noexcept:
            _name(name)
    {}

    Identifier(Identifier && that) noexcept:
            _name(std::move(that._name))
    {}

    Identifier(const Identifier & that) noexcept:
            _name(that._name)
    {}

    std::string name() const noexcept {
        return std::string(_name);
    }

    std::string & name() noexcept {
        return _name;
    }

    void name(std::string && name) noexcept {
        _name = std::move(name);
    }

    void name(const std::string & name) noexcept {
        _name = name;
    }

private:
    std::string _name;
};

}
