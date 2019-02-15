#pragma once

#include <stdbool.h>

extern void * makeNodesEmpty();
extern void * makeNodes(void * node);
extern void * pushNode(void * vector, void * node);

extern void * makeIdentifier(char * name);

extern void * makeIntegerNumericType();
extern void * makeFloatNumericType();
extern void * setNumericTypeSigned(void * type, bool _signed);
extern void * setNumericTypeBits(void * type, unsigned bits);

extern void * makeVariableDefineStmtT(void * name, void * type);
extern void * makeVariableDefineStmtV(void * name, void * value);
extern void * makeVariableDefineStmt(void * name, void * type, void * value);

extern void * makeExpressionStmt(void * expr);

extern void * makeReturnStmt(void * value);

extern void * parseIntegerLiteral(char * text);
extern void * parseFloatLiteral(char * text);
extern void * parseCharLiteral(char * text);
