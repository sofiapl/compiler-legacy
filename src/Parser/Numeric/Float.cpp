#include "Float.hpp"

void Parser::Numeric::Float::initValue() {
    value = new Node::Expr::Value::Numeric::Float(new Node::Type::Numeric::Float(), nullptr, 10);
}

bool Parser::Numeric::Float::isNumberChar(char c) {
    if (!dot && c == '.') {
        dot = true;
        return true;
    }

    int n = NUMBERS[static_cast<int>(c)];

    return n >= 0 && n < value->radix;
}

bool Parser::Numeric::Float::handleTypeChar(char c) {
    switch (c) {
        case 'F':
        case 'f':
            value->type->bits = 32;
            break;

        case 'D':
        case 'd':
            value->type->bits = 64;
            break;

        default:
            return false;
    }

    return true;
}

void Parser::Numeric::Float::makeNumberValue(const std::string & number) {
    throw std::string("unsupported"); // TODO
    // TODO value->value = new llvm::APFloat(value->type->bits, number, value->radix);
}
