#include <string.h>

int lengthOfLongestSubstring(char* s)
{
    int len = strlen(s);

    if (len <= 1)
        return len;

    int last_seen[256];
    memset(last_seen, -1, sizeof(last_seen));

    int result = 0;
    int left = 0;

    for (int right = 0; right < len; right++) {
        unsigned char symbol = (unsigned char)s[right];
        
        if (left <= last_seen[symbol])
            left = last_seen[symbol] + 1;

        last_seen[symbol] = right;
        int size = right - left + 1;
        if (size > result)
            result = size;
    }
    return result;
}