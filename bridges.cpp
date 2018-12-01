#include <vector>

#include "Node/Stmt/VariableDefine.hpp"
#include "Node/Stmt/Expression.hpp"
#include "Node/Stmt/Return.hpp"

extern "C" {

using namespace Node;

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

Type * makeType(char * name) {
    return new Type(name);
}

Stmt::VariableDefine * makeVariableDefineStmtT(void * name, void * type) {
    return new Stmt::VariableDefine(static_cast<Identifier *>(name), static_cast<Type *>(type));
}

Stmt::VariableDefine * makeVariableDefineStmtV(void * name, void * value) {
    return new Stmt::VariableDefine(static_cast<Identifier *>(name), static_cast<Expr_ *>(value));
}

Stmt::VariableDefine * makeVariableDefineStmt(void * name, void * type, void * value) {
    return new Stmt::VariableDefine(static_cast<Identifier *>(name), static_cast<Type *>(type), static_cast<Expr_ *>(value));
}

Stmt::Expression * makeExpressionStmt(void * expr) {
    return new Stmt::Expression(static_cast<Expr_ *>(expr));
}

Stmt::Return * makeReturnStmt(void * value) {
    return new Stmt::Return(static_cast<Expr_ *>(value));
}

}
