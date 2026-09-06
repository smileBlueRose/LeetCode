#include <string.h>


char* minWindow(char* s, char* t)
{
    int s_len = strlen(s);
    int t_len = strlen(t);

    if (s_len < t_len)
        return calloc(1, sizeof(char));

    int letters[256] = {0};
    for (int i = 0; i < t_len; i++)
        letters[(unsigned char)t[i]]++;

    int mismatch_count = t_len;
    int res_left = -1;
    int res_right = -1;

    int left = 0;
    int right = 0;
    for (; right < s_len; right++) {
        unsigned char right_symbol = (unsigned char)s[right];
        letters[right_symbol]--;
        if (letters[right_symbol] >= 0)
            mismatch_count--;

        while (letters[(unsigned char)s[left]] < 0) {
            letters[(unsigned char)s[left]]++;
            left++;
        }

        if (mismatch_count == 0) {
            if (res_left == -1 || (right - left + 1) < (res_right - res_left + 1)) {
                res_left = left;
                res_right = right;
            }
        }
    }
    if (res_left != -1) {
        int window_width = res_right - res_left + 1;
        char* res = malloc(sizeof(char) * (window_width + 1));
        strncpy(res, s + res_left, window_width);
        res[window_width] = '\0';
        return res;
    }

    return calloc(1, sizeof(char));
}