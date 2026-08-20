#include <stdbool.h>
#include <string.h>

bool isValid(char* s) {
    int len = strlen(s);
    char* stack = (char*)malloc(len + 1);
    int pos = -1;

    for (int i = 0; i < len; i++) {
        if (pos >= 0 && (s[i] == ')' && stack[pos] == '(' ||
                         s[i] == ']' && stack[pos] == '[' ||
                         s[i] == '}' && stack[pos] == '{')) {
            pos--;
        } else {
            pos++;
            stack[pos] = s[i];
        }
    }
    free(stack);
    return pos == -1;
}