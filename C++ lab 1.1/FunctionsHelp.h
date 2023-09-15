#ifndef HELPERS_H
#define HELPERS_H
#include "StringNode.h"
#include <iostream>
#include "StringList.h"

void addString(StringList& sl);
int inputNum();
void removeString(StringList& sl);
void autoAddString(StringList& sl);
void printStrings(const StringList& sl);
void interactWithString(StringList& sl);

#endif // HELPERS_H