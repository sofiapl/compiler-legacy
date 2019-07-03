#include <vector>

#include "ast/Node.hpp"
#include "ast/Node/Stmt/VariableDefine.hpp"
#include "ast/Node/Expr/VariableFetch.hpp"
#include "ast/Node/Expr/FunctionCall.hpp"
#include "ast/Node/Expr/SingleExprFunction.hpp"
#include "ast/Node/Expr/Function/Argument.hpp"
#include "ast/Node/Expr/Value/String.hpp"

int main() {
    std::vector<const ast::Node *> ast {
        new ast::Node::Stmt::VariableDefine("main", nullptr,
            new ast::Node::Expr::SingleExprFunction({
                    new ast::Node::Expr::Function::Argument("action", nullptr, nullptr)
                }, new ast::Node::Expr::FunctionCall(
                    new ast::Node::Expr::VariableFetch("printf"),
                    {
                        new ast::Node::Expr::Value::String("Hello, World!")
                    }
                ), nullptr
            )
        )
    };

    return 0;
}