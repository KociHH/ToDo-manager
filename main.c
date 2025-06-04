#include <stdio.h>
#include "tasks.h"

int main() {
    int choice;

    while (1) {
        printf("\n--- ToDo Менеджер ---\n");
        printf("1. Показать задачи\n");
        printf("2. Добавить задачу\n");
        printf("3. Отметить задачу как выполненную\n");
        printf("0. Выйти\n");
        printf("Ваш выбор: ");
        scanf("%d", &choice);

        while (getchar() != '\n');

        switch (choice) {
            case 1:
                show_tasks();
                break;
            case 2:
                add_task("none");
                break;
            case 3:
                complete_task();
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