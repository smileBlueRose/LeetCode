#include <stdbool.h>
#include <string.h>


bool checkInclusion(char* s1, char* s2)
{
    int letters[26] = {0};
    int s1_len = strlen(s1);
    int s2_len = strlen(s2);
    int mismatch_counter = s1_len;

    if (s1_len > s2_len)
        return false;

    for (int i = 0; i < s1_len; i++)
        letters[(unsigned char)s1[i] - 'a']++;

    for (int i = 0; i < s1_len; i++) {
        unsigned char symbol = (unsigned char)s2[i] - 'a';
        letters[symbol]--;
        if (letters[symbol] >= 0)
            mismatch_counter--;
        else
            mismatch_counter++;
    }
    if (mismatch_counter == 0)
        return true;

    int left = 0;
    int right = s1_len - 1;
    while (right < s2_len - 1) {
        unsigned char right_symbol = (unsigned char)s2[++right] - 'a';
        unsigned char left_symbol = (unsigned char)s2[left++] - 'a';
        
        letters[right_symbol]--;
        if (letters[right_symbol] >= 0)
            mismatch_counter--;
        else
            mismatch_counter++;

        letters[left_symbol]++;
        if (letters[left_symbol] <= 0)
            mismatch_counter--;
        else
            mismatch_counter++;

        if (mismatch_counter == 0)
            return true;
    }
    return false;
}