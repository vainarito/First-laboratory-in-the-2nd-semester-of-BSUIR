#define _CRT_SECURE_NO_WARNINGS
#include "StringNode.h"

// Constructor
StringNode::StringNode(const char* str) : size(strlen(str)), data(new char[size + 1]), next(nullptr), prev(nullptr)
{
    strcpy(data, str);
}

// Destructor
StringNode::~StringNode()
{
    delete[] data;
}

// Insert a string into the node's string
void StringNode::insert(const char* str, const char* after)
{
    if (after == nullptr)
    {
        // Добавить в начало строки
        int newSize = size + strlen(str) + 1; // Добавляем 1 для пробела

        char* newData = new char[newSize + 1];

        strcpy(newData, str);
        strcat(newData, " "); // Добавляем пробел
        strcat(newData, data);

        delete[] data;

        data = newData;
        size = newSize;
    }

    else
    {
        // Добавить после определенного слова
        char* pos = data;
        int count = 0;

        while ((pos = strstr(pos, after)) != nullptr)
        {
            ++count;
            pos += strlen(after); // Перемещаемся к следующему возможному вхождению
        }

        if (count == 0)
        {
            std::cout << "В тексте нет такого слова." << std::endl;
            return; // Слово не найдено
        }

        else if (count == 1)
        {
            pos = strstr(data, after);
            pos += strlen(after); // Перемещаемся к следующему возможному вхождению

            int index = pos - data + 1; // Добавляем 1 для пробела

            int newSize = size + strlen(str) + 1; // Добавляем 1 для пробела

            char* newData = new char[newSize + 1];

            strncpy(newData, data, index);
            newData[index] = '\0';

            strcat(newData, str);
            strcat(newData, " "); // Добавляем пробел
            strcat(newData, data + index);

            delete[] data;

            data = newData;
            size = newSize;
        }

        else
        {
            std::cout << "В тексте " << count << " раза встречается слово '" << after << "'. После какого надо вставить?" << std::endl;

            int occurrence;

            std::cout << "Введите число: ";

            while (!(std::cin >> occurrence) || occurrence < 1 || occurrence > count)
            {
                std::cin.clear(); // очистить флаги ошибок
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // игнорировать некорректный ввод
                std::cout << "Нет такого вхождения слова. Пожалуйста, введите число от 1 до " << count << ": ";
            }


            pos = data;

            for (int i = 0; i < occurrence; ++i)
            {
                pos = strstr(pos, after);
                pos += strlen(after); // Перемещаемся к следующему возможному вхождению
            }

            int index = pos - data + 1; // Добавляем 1 для пробела
            int newSize = size + strlen(str) + 1; // Добавляем 1 для пробела
            char* newData = new char[newSize + 1];

            strncpy(newData, data, index);
            newData[index] = '\0';

            strcat(newData, str);
            strcat(newData, " "); // Добавляем пробел
            strcat(newData, data + index);

            delete[] data;

            data = newData;
            size = newSize;
        }
    }
}

// Remove a substring from the node's string
void StringNode::removeSubstring(const char* start, const char* end)
{
    char* startPos = strstr(data, start);

    if (startPos == nullptr)
    {
        std::cout << "ОШИБКА! В строке нет слова '" << start << "'." << std::endl;
        return;
    }

    int startCount = 0;
    char* tempPos = startPos;

    while ((tempPos = strstr(tempPos, start)) != nullptr)
    {
        ++startCount;
        tempPos += strlen(start);
    }

    int startOccurrence = 1;

    std::cout << "В строке " << startCount << " раза встречается подстрока '" << start << "'. С какого слова начинать удаление (включая его): ";

    while (!(std::cin >> startOccurrence) || startOccurrence < 1 || startOccurrence > startCount)
    {
        std::cin.clear(); // очистить флаги ошибок
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // игнорировать некорректный ввод
        std::cout << "ОШИБКА! Нет такого вхождения слова. Пожалуйста, введите число от 1 до " << startCount << ": ";
    }

    tempPos = startPos;

    for (int i = 1; i < startOccurrence; ++i)
    {
        tempPos = strstr(tempPos + strlen(start), start);
    }

    startPos = tempPos;

    char* endPos = strstr(data, end);

    if (endPos == nullptr)
    {
        std::cout << "ОШИБКА! В строке нет слова '" << end << "'." << std::endl;
        return;
    }

    int endCount = 0;
    tempPos = endPos;

    while ((tempPos = strstr(tempPos, end)) != nullptr)
    {
        ++endCount;
        tempPos += strlen(end);
    }

    int endOccurrence = 1;

    std::cout << "В строке " << endCount << " раза встречается подстрока '" << end << "'. До какого слова надо удалять (включая его): ";

    while (!(std::cin >> endOccurrence) || endOccurrence < 1 || endOccurrence > endCount)
    {
        std::cin.clear(); // очистить флаги ошибок
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // игнорировать некорректный ввод
        std::cout << "ОШИБКА! Нет такого вхождения слова. Пожалуйста, введите число от 1 до " << endCount << ": ";
    }


    tempPos = endPos;

    for (int i = 1; i < endOccurrence; ++i)
    {
        tempPos = strstr(tempPos + strlen(end), end);
    }

    if (tempPos < startPos)
    {
        std::cout << "ОШИБКА! Конечное слово не может находиться раньше начального." << std::endl;
        return;
    }

    tempPos += strlen(end);

    if (*tempPos == ' ')
    {
        ++tempPos;
    }

    int newSize = size - (tempPos - startPos);

    char* newData = new char[newSize + 1];

    strncpy(newData, data, startPos - data);

    newData[startPos - data] = '\0';

    strcat(newData, tempPos);

    delete[] data;
    data = newData;

    size = newSize;
    system("cls");
}

// Replace a substring in the node's string with another substring
void StringNode::replaceSubstring(const char* oldSubstring, const char* newSubstring)
{
    char* pos = strstr(data, oldSubstring);

    if (pos == nullptr)
    {
        std::cout << "ОШИБКА! В строке нет подстроки '" << oldSubstring << "'." << std::endl;
        return;
    }

    int count = 0;

    while (pos != nullptr)
    {
        ++count;
        pos = strstr(pos + strlen(oldSubstring), oldSubstring);
    }

    int occurrence;

    std::cout << "В строке " << count << " раз(а) встречается подстрока '" << oldSubstring << "'. С каким именно вы хотите произвести замену: ";
    while (!(std::cin >> occurrence) || occurrence < 1 || occurrence > count)
    {

        std::cin.clear(); // очистить флаги ошибок
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // игнорировать некорректный ввод
        std::cout << "ОШИБКА! Нет такого вхождения слова. Пожалуйста, введите число от 1 до " << count << ": ";

    }

    pos = data;

    for (int i = 0; i < occurrence; ++i)
    {
        pos = strstr(pos, oldSubstring);
        pos += strlen(oldSubstring); // Перемещаемся к следующему возможному вхождению
    }

    int index = pos - data - strlen(oldSubstring); // Индекс начала старой подстроки
    int newSize = size - strlen(oldSubstring) + strlen(newSubstring); // Размер новой строки
    char* newData = new char[newSize + 1]; // Создаем новый массив символов для обновленной строки

    strncpy(newData, data, index); // Копируем часть строки до старой подстроки
    newData[index] = '\0'; // Добавляем нулевой символ в конце
    strcat(newData, newSubstring); // Добавляем новую подстроку
    strcat(newData, data + index + strlen(oldSubstring)); // Добавляем часть строки после старой подстроки

    delete[] data; // Удаляем старые данные
    data = newData; // Заменяем их новыми
    size = newSize; // Обновляем размер строки
}

// Find a substring in the node's string
void StringNode::findSubstring(const char* substring)
{
    char* pos = strstr(data, substring);

    if (pos == nullptr)
    {
        std::cout << "В строке нет упоминания '" << substring << "'." << std::endl;
        return;
    }

    int count = 0;

    while (pos != nullptr)
    {
        ++count;
        pos = strstr(pos + strlen(substring), substring);
    }

    std::cout << "В вашей строке " << count << " раз(а) упоминается '" << substring << "'" << std::endl;
}
