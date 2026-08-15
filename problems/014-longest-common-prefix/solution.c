char* longestCommonPrefix(char** strs, int strsSize) 
{    
    char *res = malloc(strlen(strs[0]) + 1);
    strncpy(res, strs[0], strlen(strs[0]) + 1);

    for (int i = 0; i < strsSize; ++i) 
    {
        int str_i_size = strlen(strs[i]);
        for (int pos = strlen(strs[0]); pos >= 0; --pos) 
        {
            if (pos <= str_i_size && res[pos] != strs[i][pos])
                res[pos] = '\0';
        }
    }
    
    return res;
}