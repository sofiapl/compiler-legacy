#pragma once

#include <Parser/Numeric_.hpp>
#include <Node/Expr/Value/Numeric/Float.hpp>

#include <llvm/ADT/StringRef.h>
#include <llvm/ADT/APFloat.h>

namespace Parser {

namespace Numeric {

class Float: public Numeric_ <Node::Type::Numeric::Float, llvm::APFloat> {

public:
    Float(): Numeric_() {}
    explicit Float(Node::Expr::Value::Numeric::Float * value): Numeric_(value) {}

protected:
    void initValue() override {
        value = new Node::Expr::Value::Numeric::Float(new Node::Type::Numeric::Float(), nullptr, 10);
    }

    bool isNumberChar(char c) override {
        if (c == '.' || c == '-' || c == 'E' || c == 'e') {
            return true;
        }

        int n = NUMBERS[c];

        return n >= 0 && n < value->radix;
    }

    bool handleTypeChar(char c) override {
        switch (c) {
            case 'f':
                value->type->bits = 32;
                break;

            case 'd':
                value->type->bits = 64;
                break;

            default:
                return false;
        }

        return true;
    }

    void makeNumberValue(const std::string & number) override {
        // TODO value->value = new llvm::APFloat(value->type->bits, number, value->radix);
    }
};

}

}
