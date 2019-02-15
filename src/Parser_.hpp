#pragma once

#include <string>

template <class V>
class Parser_ {

public:
    typedef V ValueType;

    V * value;

    Parser_(): value(nullptr) {}
    explicit Parser_(V * value): value(value) {}

    virtual void parse(const std::string & text) = 0;
};
