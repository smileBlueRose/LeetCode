#include <ctype.h>
#include <stdbool.h>
#include <string.h>

bool isPalindrome(char* s)
{
    char* left = s;
    char* right = s + strlen(s) - 1;

    while (left < right) {
        if (!isalnum((unsigned char)*left))
            left++;
        else if (!isalnum((unsigned char)*right))
            right--;
        else if (tolower((unsigned char)*left) !=
                 tolower((unsigned char)*right))
            return false;
        else {
            left++;
            right--;
        }
    }

    return true;
}