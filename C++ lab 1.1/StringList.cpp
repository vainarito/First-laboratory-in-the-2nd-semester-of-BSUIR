#define _CRT_SECURE_NO_WARNINGS
#include "StringList.h"

// Конструктор
StringList::StringList() : head(nullptr), tail(nullptr) {}

// Деструктор
StringList::~StringList()
{
    while (head)
    {
        StringNode* temp = head;
        head = head->next;
        delete temp;
    }
}

// Добавить строку в список
void StringList::add(const char* str)
{
    StringNode* node = new StringNode(str);

    if (tail)
    {
        tail->next = node;
        node->prev = tail;
    }
    else
    {
        head = node;
    }

    tail = node;
}

// Удалить строку из списка по индексу
void StringList::remove(int index)
{
    --index; // Корректировка для нулевой индексации
    StringNode* node = head;

    for (int i = 0; i < index && node; ++i)
    {
        node = node->next;
    }

    if (node)
    {
        if (node->prev)
        {
            node->prev->next = node->next;
        }
        else
        {
            head = node->next;
        }

        if (node->next)
        {
            node->next->prev = node->prev;
        }
        else
        {
            tail = node->prev;
        }

        delete node;
    }
}

// Вывести все строки в списке
void StringList::print() const
{
    int i = 1;
    for (StringNode* node = head; node; node = node->next, ++i)
    {
        std::cout << i << " - " << node->data << std::endl;
    }
}

// Получить строку из списка по индексу
StringNode* StringList::getNode(int index)
{
    StringNode* node = head;

    for (int i = 1; i < index && node; ++i)
    {
        node = node->next;
    }

    return node;
}
