#include <iostream>
#include <cstdlib>

char* strcat(char* pstr1, const char* pstr2)
{
    char* pstr = pstr1;
    while(pstr && *pstr)
    {
        pstr++;
    }

    while(pstr2 && *pstr2)
    {
        *pstr++ = *pstr2++;
    }
    *pstr = '\0';

    return pstr1;
}

int main()
{
    char    str1[256] = "I love ";
    char    str2[] = "cug";

    std::cout << strcat(str1, str2) << std::endl;

    return 0;
}