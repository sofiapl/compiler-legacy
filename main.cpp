#include <iostream>
#include <vector>

#include <Node_.hpp>
#include <Parser/Numeric/Integer.hpp>

extern "C" int yyparse();
extern "C" std::vector <Node_ *> * file;
std::vector <Node_ *> * file;

int main() {
    yyparse();

    return 0;
}
