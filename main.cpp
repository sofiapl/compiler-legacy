#include <iostream>
#include <vector>

#include "Node_.hpp"

extern "C" int yyparse();
extern "C" std::vector <Node_ *> * file;
std::vector <Node_ *> * file;

int main() {
    yyparse();

    return 0;
}
