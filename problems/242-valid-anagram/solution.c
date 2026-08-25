#include <string.h>
#include <stdbool.h>


bool isAnagram(char* s, char* t)
{

    int s_len = strlen(s);

    if (s_len != strlen(t))
        return false;

    unsigned short letters[26] = {0};

    for (int i = 0; i < s_len; i++)
    {
        letters[s[i] - 'a']++;
        letters[t[i] - 'a']--;
    }


    for (int i = 0; i < 26; i++)
    {
        if (letters[i] != 0)
            return false;
    }

    return true;
}