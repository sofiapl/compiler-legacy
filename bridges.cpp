#include <vector>
#include "Node/Stmt/VariableDefine.hpp"

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

Stmt::VariableDefine * makeVariableDefineT(void * name, void * type) {
    return new Stmt::VariableDefine(static_cast<Identifier *>(name), static_cast<Type *>(type));
}

Stmt::VariableDefine * makeVariableDefineV(void * name, void * value) {
    return new Stmt::VariableDefine(static_cast<Identifier *>(name), static_cast<Expr_ *>(value));
}

Stmt::VariableDefine * makeVariableDefine(void * name, void * type, void * value) {
    return new Stmt::VariableDefine(static_cast<Identifier *>(name), static_cast<Type *>(type), static_cast<Expr_ *>(value));
}

}
