#include <cstdio>
#include <vector>
#include "Node/Stmt/VariableDefine.hpp"

extern "C" int yyparse();
extern "C" std::vector <Node_ *> * file;
std::vector <Node_ *> * file;

int main() {
    yyparse();

    printf("%s", reinterpret_cast<Node::Stmt::VariableDefine *>(file->back())->name->name().c_str());

    return 0;
}
