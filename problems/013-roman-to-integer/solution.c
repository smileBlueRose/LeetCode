#include <string.h>


int romanToInt(char* s) 
{
    int t, result = 0;
    int len = strlen(s);
    
    for (int i = 0; i < len; ++i) 
    {
        if (s[i] == 'I') t = 1;
        else if (s[i] == 'V') {
            if (i > 0 && (s[i - 1] == 'I')) t = 3;
            else t = 5;
        }
        else if (s[i] == 'X') {
            if (i > 0 && (s[i - 1] == 'I')) t = 8;
            else t = 10;
        }
        else if (s[i] == 'L') {
            if (i > 0 && (s[i - 1] == 'X')) t = 30;
            else t = 50;
        }
        else if (s[i] == 'C') {
            if (i > 0 && (s[i - 1] == 'X')) t = 80;
            else t = 100;
        }
        else if (s[i] == 'D') {
            if (i > 0 && (s[i - 1] == 'C')) t = 300;
            else t = 500;
        }
        else if (s[i] == 'M') {
            if (i > 0 && (s[i - 1] == 'C')) t = 800;
            else t = 1000;
        }
        else return -1;
        
        result += t;
    }

    return result;
}