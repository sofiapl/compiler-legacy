#pragma once

extern void * makeNodesEmpty();
extern void * makeNodes(void * node);
extern void * pushNode(void * vector, void * node);

extern void * makeIdentifier(char * name);
extern void * makeType(char * name);

extern void * makeVariableDefineT(void * name, void * type);
extern void * makeVariableDefineV(void * name, void * value);
extern void * makeVariableDefine(void * name, void * type, void * value);
