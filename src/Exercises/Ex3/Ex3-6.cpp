#include <iostream>

int strlen(const char* pstr)
{
    int len = 0;
    while(pstr && *pstr)
    {
        len ++;
        pstr++;
    }

    return len;
}

int main()
{
    char    str[] = "Geosciences";
    std::cout << strlen(str) << std::endl;

    return 0;
}