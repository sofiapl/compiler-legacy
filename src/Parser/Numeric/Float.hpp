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
    void initValue() override;

    bool isNumberChar(char c) override;

    bool handleTypeChar(char c) override;

    void makeNumberValue(const std::string & number) override;

private:
    bool dot = false;
};

}

}
