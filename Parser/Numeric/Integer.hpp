#pragma once

#include <Parser/Numeric_.hpp>
#include <Node/Expr/Value/Numeric/Integer.hpp>

#include <llvm/ADT/StringRef.h>
#include <llvm/ADT/APInt.h>

namespace Parser {

namespace Numeric {

class Integer: public Numeric_ <Node::Type::Numeric::Integer, llvm::APInt> {

public:
    Integer(): Numeric_() {}
    explicit Integer(Node::Expr::Value::Numeric::Integer * value): Numeric_(value) {}

protected:
    void initValue() override {
        value = new Node::Expr::Value::Numeric::Integer(new Node::Type::Numeric::Integer(), nullptr, 10);
    }

    bool isNumberChar(char c) override {
        int n = NUMBERS[c];

        return n >= 0 && n < value->radix;
    }

    bool handleTypeChar(char c) override {
        switch (c) {
            case 'b':
                value->type->bits = 8;
                break;

            case 's':
                value->type->bits = 16;
                break;

            case 'i':
                value->type->bits = 32;
                break;

            case 'l':
                value->type->bits = 64;
                break;

            default:
                return false;
        }

        return true;
    }

    void makeNumberValue(const std::string & number) override {
        value->value = new llvm::APInt(value->type->bits, number, value->radix);
    }
};

}

}
