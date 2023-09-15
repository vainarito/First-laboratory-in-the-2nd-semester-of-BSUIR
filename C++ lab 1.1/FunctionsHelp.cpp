#define _CRT_SECURE_NO_WARNINGS
#include "FunctionsHelp.h"
#define MEMORY 256


void addString(StringList& sl)
{
    std::cin.ignore();
    char str[MEMORY];
    std::cout << "Введите строку: ";
    std::cin.getline(str, MEMORY);
    sl.add(str);
}

int inputNum()
{
    int index;
    while (!(std::cin >> index))
    {
        std::cin.clear(); // очистить флаги ошибок
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // игнорировать некорректный ввод
        std::cout << "Некорректный ввод. Пожалуйста, введите число: ";
    }
    return index;
}

void removeString(StringList& sl)
{
    system("cls");
    sl.print();

    std::cout << "Введите номер строки для удаления: ";
    int index = inputNum();

    sl.remove(index);
}

void autoAddString(StringList& sl)
{
    system("cls");
    sl.add("Hello world TEST Hello world TEST Hello world TEST");
}

void printStrings(const StringList& sl)
{
    system("cls");
    sl.print();
}

void interactWithString(StringList& sl)
{
    int index;
    int choiseNumTwo;
    int choiseNumThree;

    std::cout << "Введите номер строки для взаимодействия: ";
    index = inputNum();
    system("cls");

    do {
        sl.print();
        std::cout << "1. Добавить новый текст в строку\n2. Удалить из строки подстроку\n3. Заменить подстроку на другую подстроку\n4. Найти подстроку в строке\n5. Выход в меню\nВаш выбор:";
        choiseNumTwo = inputNum();

        switch (choiseNumTwo) {

        case 1: {
            std::cin.ignore();
            char str[MEMORY];
            std::cout << "Введите текст для добавления: ";
            std::cin.getline(str, MEMORY);

            std::cout << "Выберите как вставлять текст:\n1. В начало строки\n2. После определённого слова\nВаш выбор:";
            choiseNumThree = inputNum();

            // Найдите узел с индексом 'index'
            StringNode* node = sl.getNode(index);

            // Если узел найден, вызовите метод 'insert'
            if (node)
            {
                if (choiseNumThree == 1)
                {
                    node->insert(str);
                }

                else if (choiseNumThree == 2)
                {
                    std::cin.ignore();
                    char after[MEMORY];
                    std::cout << "Введите слово, после которого нужно добавить текст: ";
                    std::cin.getline(after, MEMORY);
                    node->insert(str, after);
                }

                else {
                    std::cout << "Нет такого варианта!" << std::endl;
                }
            }

            else
            {
                std::cout << "Строка с указанным номером не найдена." << std::endl;
            }

            break;
        }

        case 2: {
            std::cin.ignore();
            char start[MEMORY], end[MEMORY];
            std::cout << "Введите начальное слово для удаления: ";
            std::cin.getline(start, MEMORY);
            std::cout << "Введите конечное слово для удаления: ";
            std::cin.getline(end, MEMORY);

            // Найдите узел с индексом 'index'
            StringNode* node = sl.getNode(index);

            // Если узел найден, вызовите метод 'removeSubstring'
            if (node)
            {
                node->removeSubstring(start, end);
            }

            else
            {
                std::cout << "Строка с указанным номером не найдена." << std::endl;
            }

            break;
        }

        case 3:
        {
            std::cin.ignore();
            char oldSubstring[MEMORY], newSubstring[MEMORY];
            std::cout << "Введите подстроку для замены: ";
            std::cin.getline(oldSubstring, MEMORY);
            std::cout << "На что вы хотите поменять '" << oldSubstring << "': ";
            std::cin.getline(newSubstring, MEMORY);

            // Найдите узел с индексом 'index'
            StringNode* node = sl.getNode(index);

            // Если узел найден, вызовите метод 'replaceSubstring'
            if (node)
            {
                node->replaceSubstring(oldSubstring, newSubstring);
            }

            else
            {
                std::cout << "Строка с указанным номером не найдена." << std::endl;
            }

            break;
        }

        case 4:
        {
            std::cin.ignore();
            char substring[MEMORY];
            std::cout << "Введите подстроку для поиска: ";
            std::cin.getline(substring, MEMORY);
            system("cls");
            // Найдите узел с индексом 'index'
            StringNode* node = sl.getNode(index);

            // Если узел найден, вызовите метод 'findSubstring'
            if (node)
            {
                node->findSubstring(substring);
            }

            else
            {
                std::cout << "Строка с указанным номером не найдена." << std::endl;
            }

            break;
        }

        case 5:
            // Выход из меню взаимодействия со строкой
            break;

        default:
            std::cout << "Нет такого варианта!" << std::endl;
            break;
        }

    } while (choiseNumTwo != 5);
}