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
    void initValue() override;

    bool isNumberChar(char c) override;

    bool handleTypeChar(char c) override;

    void makeNumberValue(const std::string & number) override;
};

}

}
