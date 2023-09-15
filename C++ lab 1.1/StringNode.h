#ifndef STRINGNODE_H
#define STRINGNODE_H
#include <iostream>  
#include <cstring>

class StringNode
{
public:
    StringNode(const char* str);
    ~StringNode();
    void insert(const char* str, const char* after = nullptr);
    void removeSubstring(const char* start, const char* end);
    void replaceSubstring(const char* oldSubstring, const char* newSubstring);
    void findSubstring(const char* substring);

    int size;
    char* data;
    StringNode* next;
    StringNode* prev;
};

#endif // STRINGNODE_H
