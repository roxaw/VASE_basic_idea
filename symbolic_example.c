#include <stdio.h>
#include <string.h>
#include "/home/roxana/asm/asm/stub_model/header-new/klee.h"

#define MAX_LEN 10

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
    return result;
}

int main() {
    char input[MAX_LEN + 1];
    int total = 0;

    // Make the input symbolic
    klee_make_symbolic(input, sizeof(input), "input");
    input[MAX_LEN] = '\0'; // Null-terminate the string

    // Process each character in the input
    for (int i = 0; i < MAX_LEN; i++) {
        for (int j = 0; j < i; j++) {
            total += process_char(input[j]);
        }
    }

    return 0;
}
