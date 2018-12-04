#pragma once

#include <stdbool.h>

extern void * makeNodesEmpty();
extern void * makeNodes(void * node);
extern void * pushNode(void * vector, void * node);

extern void * makeIdentifier(char * name);

extern void * makeNumericType(unsigned char mask, bool _signed, unsigned char bits, bool integer);

extern void * makeVariableDefineStmtT(void * name, void * type);
extern void * makeVariableDefineStmtV(void * name, void * value);
extern void * makeVariableDefineStmt(void * name, void * type, void * value);

extern void * makeExpressionStmt(void * expr);

extern void * makeReturnStmt(void * value);
