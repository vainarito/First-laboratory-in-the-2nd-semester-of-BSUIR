#define _CRT_SECURE_NO_WARNINGS
#include "FunctionsHelp.h"


int main() {

    StringList sl;

    int choice;

    do {
        std::cout << "1. Добавить новую строку\n";
        std::cout << "2. Удалить строку\n";
        std::cout << "3. Автоматически добавить строку\n";
        std::cout << "4. Вывести все строки\n";
        std::cout << "5. Выбрать строку для взаимодействия\n";
        std::cout << "6. Выход\n";

        choice = inputNum();

        switch (choice) {

        case 1:
            system("cls");
            addString(sl);
            break;

        case 2:
            system("cls");
            removeString(sl);
            break;

        case 3:
            autoAddString(sl);
            break;

        case 4:
            printStrings(sl);
            break;

        case 5:
            system("cls");
            sl.print();
            interactWithString(sl);
            break;

        case 6:
            break;

        default:
            std::cout << "Неверный выбор. Пожалуйста, попробуйте снова.\n";
            break;

        }

    } while (choice != 6);

    return 0;
}
