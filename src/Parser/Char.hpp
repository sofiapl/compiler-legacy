#pragma once

#include <Parser_.hpp>
#include <Node/Expr/Value/Char.hpp>
#include <Node/Type/Numeric/Integer.hpp>

#include <string>

namespace Parser {

class Char: public Parser_ <Node::Expr::Value::Char> {

public:
    Char(): Parser_ <Node::Expr::Value::Char> () {}

    explicit Char(Node::Expr::Value::Char * value):
            Parser_ <Node::Expr::Value::Char> (value)
    {}

    void parse(std::string && text) override {
        using namespace Node::Expr;

        if (value == nullptr) {
            value = new Value::Char(nullptr);
        }

        // TODO

        const char * cursor = text.c_str();
        for (int i = 0; * cursor; ++i) {
            // TODO One char parsing

            ++cursor;
        }
    }
};

}
