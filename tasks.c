#include <stdio.h>
#include <string.h>
#include "import/tasks.h"
#include "import/utils.h"

#define max_tasks 100
#define max_len 100

Task tasks[max_tasks];
int task_count = 0;
char str_exit[100] = "(или введите 'exit' для выхода)";

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

void add_task(void) {
    if (task_count >= max_tasks) {
        printf("Достигнут лимит задач! Удалите одну.\n");
        return;
    }

    char input[max_len];
    while (1) {
        printf("Введите текст задачи %s: ", str_exit);
        
        if (!fgets(input, max_len, stdin)) {
            clearerr(stdin);
            continue;
        }

        if (strchr(input, '\n') == NULL) {
            int ch;
            while ((ch == getchar()) != '\n' && ch != EOF);
        }

        input[strcspn(input, "\n")] = '\0';
        printf("[DEBUG] Введено: '%s', длина: %zu\n", input, strlen(input));

        if (is_exit_command(input)) return;

        if (strlen(input) == 0) {
            printf("Пустая задача недопустима!\n");
            continue;
        }

        strcpy(tasks[task_count].text, input);
        tasks[task_count].completed = 0;
        task_count++;
        printf("Задача '%s' добавлена под индексом [%d].\n", 
              tasks[task_count-1].text, task_count);
        break;
    }
}

void complete_task(void) {
    int num;
    char exit_input[10];
    printf("Введите номер задачи для отметки как выполненной %s: ", str_exit);
    
    if (scanf("%d", &num) != 1) {
        scanf("%s", exit_input);
        if (is_exit_command(exit_input)) {
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

void delete_task(void) {
    if (task_count == 0) {
        printf("Нет задач для удаления! С начала добавьте ее.\n");
        return;
    }

    int num;
    char str[10];

    printf("Введите номер задачи для удаления %s: ", str_exit);
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';

    if (is_exit_command(str)) return;

    if (sscanf(str, "%d", &num) != 1) {
        printf("Неверный формат номера!\n");
        return;
    }

    if (num < 1 || num  > task_count) {
        printf("Неверный номер задачи! Допустимый диапозон: 1-%d\n", task_count);
        return;
    }

    char deleted_text[max_len];
    strcpy(deleted_text, tasks[num - 1].text);

    for (int i = num - 1; i < task_count - 1; i++) {
        tasks[i] = tasks[i + 1];
    }
    task_count--;

    printf("Задача '%s' под индексом [%d] была удалена!\n", deleted_text, num);
}