#include <stdio.h>
#include "import/tasks.h"
#include "Windows.h"
#include <locale.h>


// gcc main.c tasks.c utils.c -o output/main.exe
// output/main.exe

int main() {
    int choice;
    char input[20];
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);

    while (1) {
        printf("\n--- ToDo Менеджер ---\n");
        printf("1. Показать задачи\n");
        printf("2. Добавить задачу\n");
        printf("3. Отметить задачу как выполненную\n");
        printf("4. Удалить задачу\n");
        printf("0. Выйти\n");
        printf("Ваш выбор: ");

        fgets(input, sizeof(input), stdin);
        if (sscanf(input, "%d", &choice) != 1) {
            printf("Ошибка: пожалуйста введите число!\n");
            continue;
        }

        switch (choice) {
            case 1:
                show_tasks();
                break;
            case 2:
                add_task();
                break;
            case 3:
                complete_task();
                break;
            case 4:
                delete_task();
                break;
            case 0:
                printf("Выход...\n");
                return 0;
            default:
                printf("Неверный выбор!\n");
        }
    }
    return 0;
}