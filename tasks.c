#include <stdio.h>
#include <string.h>
#include "tasks.h"

#define max_tasks 100
#define max_len 100

Task tasks[max_tasks];
int task_count = 0;

void show_tasks() {
    printf("\nСписок задач:\n");
    if (task_count == 0) {
        printf("Нет задач.\n");
        return;
    }
    for (int i = 0; i < task_count; i++) {
        printf("%d. [%c] %s\n", i + 1, tasks[i].completed ? 'X' : ' ', tasks[i].text);
    }
}

void add_task(const char *last_task) {
    if (task_count >= max_tasks) {
        printf("Вы достигли лимит задач!\n Освободите место для %s.\n", last_task);
        return;
    }
    printf("Введите текст задачи: ");
    getchar();
    fgets(tasks[task_count].text, max_len, stdin);
    tasks[task_count].text[strcspn(tasks[task_count].text, "\n")] = 0;
    tasks[task_count].completed = 0;
    task_count++;
    printf("Задача добавлена! Под индексом [%d] .\n", task_count);
    if (task_count > max_len - 5 && task_count != max_tasks) {
        printf("Внимание! У вас скоро будет достигнут лимит задач, т.е через %d внесений.\n", max_len - task_count);
    }
}

void complete_task(void) {
    int num;
    char exit_input[10];
    printf("Введите номер задачи для отметки как выполненной (или введите 'exit' для выхода): ");
    if (scanf("%d", &num) != 1) {
        scanf("%s", exit_input);
        if (strcmp(exit_input, "exit") == 0) {
            return;
        } else {
            printf("Неверный ввод!\n");
            while (getchar() != '\n');
            return complete_task();
        }
    }
    if (num < 1 || num > task_count) {
        printf("Неверный номер задачи!\n");
        return complete_task();
    }
    tasks[num - 1].completed = 1;
    printf("Задача \"%s\" с индексом %d была отмечена!\n", tasks[num - 1].text, num);
}
