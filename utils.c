#include <stdio.h>
#include <string.h>

int is_exit_command(const char *input) {
    return strcmp(input, "exit") == 0 ? 1 : 0;
}