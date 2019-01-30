#include "Integer.hpp"

void Parser::Numeric::Integer::initValue() {
    value = new Node::Expr::Value::Numeric::Integer(new Node::Type::Numeric::Integer(), nullptr, 10);
}

bool Parser::Numeric::Integer::isNumberChar(char c) {
    int n = NUMBERS[static_cast<int>(c)];

    return n >= 0 && n < value->radix;
}

bool Parser::Numeric::Integer::handleTypeChar(char c) {
    switch (c) {
        case 'B':
        case 'b':
            value->type->bits = 8;
            break;

        case 'S':
        case 's':
            value->type->bits = 16;
            break;

        case 'I':
        case 'i':
            value->type->bits = 32;
            break;

        case 'L':
        case 'l':
            value->type->bits = 64;
            break;

        default:
            return false;
    }

    return true;
}

void Parser::Numeric::Integer::makeNumberValue(const std::string & number) {
    value->value = new llvm::APInt(value->type->bits, number, value->radix);
}
