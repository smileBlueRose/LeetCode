#include <string.h>

int characterReplacement(char* s, int k)
{
    int len = strlen(s);
    int count[26] = {0};
    int res = 0;
    int max_freq = 0;
    int left = 0;

    for (int right = 0; right < len; right++) {
        count[s[right] - 'A']++;
        if (count[s[right] - 'A'] > max_freq) {
            max_freq = count[s[right] - 'A'];
        }
        int window = right - left + 1;
        if (window - max_freq > k) {
            count[s[left] - 'A']--;
            left++;
        }
        window = right - left + 1;
        if (window > res)
            res = window;
    }
    return res;
}