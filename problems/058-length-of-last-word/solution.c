#include <stdbool.h>


int length_of_last_word(char* s) {
    char *ptr = s;
    while (true) {
        if (*ptr == '\0') break;
        ptr++;
    }
    
    while (true) {
        ptr--;
        if (*ptr != ' ') break;
    }
    
    int len = 0;
    while (true) {
        if (*ptr == ' ') break;
        if (ptr == s) {
            len++;
            break;
        }
        ptr--;
        len++;
    }

    return len;
}