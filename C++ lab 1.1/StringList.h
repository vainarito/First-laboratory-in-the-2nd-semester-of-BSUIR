#ifndef STRINGLIST_H
#define STRINGLIST_H

#include "StringNode.h"
#include <iostream>

class StringList
{
public:
    StringList();
    ~StringList();
    void add(const char* str);
    void remove(int index);
    void print() const;
    StringNode* getNode(int index);

private:
    StringNode* head;
    StringNode* tail;
};

#endif // STRINGLIST_H