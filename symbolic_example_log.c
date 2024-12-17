#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "/home/roxana/asm/asm/stub_model/header-new/klee.h"

#define MAX_LEN 5

int process_char(char c) {
    int result = 0;
    if (c == 'a') {
        result += 1;
    } else if (c == 'b') {
        result += 2;
    } else if (c == 'c') {
        result += 3;
    } else {
        result += 4;
    }
    klee_print_expr("process_char result: ", result); // Logging statement
    return result;
}

void run_with_input(const char *input) {
    int total = 0;
   klee_print_expr("Running with input: %s\n", input);
    for (int i = 0; i < MAX_LEN; i++) {
        for (int j = 0; j < i; j++) {
            total += process_char(input[j]);
            klee_print_expr("main total: ", total); // Logging statement
        }
    }
}

void generate_and_run_inputs() {
    char input[MAX_LEN + 1];
    srand(time(NULL));
    for (int len = 1; len <= MAX_LEN; len++) {
        for (int i = 0; i < len; i++) {
            input[i] = 'a' + rand() % 4; // Random character 'a', 'b', 'c', or 'd'
        }
        input[len] = '\0';
        run_with_input(input);
    }
}

int main() {
    generate_and_run_inputs();
    return 0;
}
