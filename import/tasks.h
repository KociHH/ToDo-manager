#ifndef TASKS_H
#define TASKS_H

#define max_tasks 100
#define max_len 100

typedef struct {
    char text[max_len];
    int completed;
} Task;

extern Task tasks[max_tasks];
extern int task_count;

void show_tasks(void);
void add_task(void);
void complete_task(void);
void delete_task(void);

#endif