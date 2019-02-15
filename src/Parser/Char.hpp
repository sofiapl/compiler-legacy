#pragma once

#include <Parser_.hpp>
#include <Node/Expr/Value/Char.hpp>
#include <Node/Type/Numeric/Integer.hpp>

#include <codecvt>
#include <locale>
#include <string>

namespace Parser {

class Char: public Parser_ <Node::Expr::Value::Char> {

public:
    static std::u16string prepareUnicode(const std::string & text);

    Char(): Parser_ <Node::Expr::Value::Char> () {}

    explicit Char(Node::Expr::Value::Char * value):
            Parser_ <Node::Expr::Value::Char> (value)
    {}

    void parse(const std::string & text) override;
};

}
