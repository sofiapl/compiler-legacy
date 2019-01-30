#include <vector>

#include <Node/Stmt/VariableDefine.hpp>
#include <Node/Stmt/Expression.hpp>
#include <Node/Stmt/Return.hpp>
#include <Node/Type/Numeric_.hpp>
#include <Node/Type/Numeric/Integer.hpp>
#include <Node/Type/Numeric/Float.hpp>
#include <Node/Expr/Value/Numeric/Integer.hpp>

#include <Parser/Numeric/Integer.hpp>
#include <Parser/Numeric/Float.hpp>

#include <llvm/ADT/StringRef.h>

extern "C" {

using namespace Node;

void yyerror(const char *);

std::vector <Node_ *> * makeNodesEmpty() {
    return new std::vector <Node_ *>;
}

std::vector <Node_ *> * makeNodes(void * node) {
    auto vector = makeNodesEmpty();
    vector->push_back(static_cast<Node_ *>(node));

    return vector;
}

std::vector <Node_ *> * pushNode(void * _vector, void * node) {
    auto vector = static_cast<std::vector <Node_ *> *> (_vector);
    vector->push_back(static_cast<Node_ *>(node));

    return vector;
}

Identifier * makeIdentifier(char * name) {
    return new Identifier(name);
}

Type::Numeric::Integer * makeIntegerNumericType() {
    return new Type::Numeric::Integer();
}

Type::Numeric::Float * makeFloatNumericType() {
    return new Type::Numeric::Float();
}

Type::Numeric_ * setNumericTypeSigned(void * type, bool _signed) {
    static_cast<Type::Numeric_ *>(type)->_signed = _signed;
    return static_cast<Type::Numeric_ *>(type);
}

Type::Numeric_ * setNumericTypeBits(void * type, Node::Type::Numeric_::BitsType bits) {
    static_cast<Type::Numeric_ *>(type)->bits = bits;
    return static_cast<Type::Numeric_ *>(type);
}

Stmt::VariableDefine * makeVariableDefineStmtT(void * name, void * type) {
    return new Stmt::VariableDefine(static_cast<Identifier *>(name), static_cast<Type_ *>(type));
}

Stmt::VariableDefine * makeVariableDefineStmtV(void * name, void * value) {
    return new Stmt::VariableDefine(static_cast<Identifier *>(name), static_cast<Expr_ *>(value));
}

Stmt::VariableDefine * makeVariableDefineStmt(void * name, void * type, void * value) {
    return new Stmt::VariableDefine(static_cast<Identifier *>(name), static_cast<Type_ *>(type), static_cast<Expr_ *>(value));
}

Stmt::Expression * makeExpressionStmt(void * expr) {
    return new Stmt::Expression(static_cast<Expr_ *>(expr));
}

Stmt::Return * makeReturnStmt(void * value) {
    return new Stmt::Return(static_cast<Expr_ *>(value));
}

Expr::Value::Numeric::Integer * parseIntegerLiteral(char * text) {
    auto parser = new Parser::Numeric::Integer();

    try {
        parser->parse(text);
    } catch (const std::string & e) {
        yyerror(e.c_str());
        return nullptr;
    }

    return parser->value;
}

Expr::Value::Numeric::Float * parseFloatLiteral(char * text) {
    auto parser = new Parser::Numeric::Float();

    try {
        parser->parse(text);
    } catch (const std::string & e) {
        yyerror(e.c_str());
        return nullptr;
    }

    return parser->value;
}

}
