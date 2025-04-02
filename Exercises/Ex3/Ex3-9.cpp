#include <iostream>

int str_to_int(const char* pstr)
{
    int     val = 0;
    while(pstr && *pstr)
    {
        val = 10*val + *pstr-'0';
        pstr++;
    }

    return val;
}

int main()
{
    const char  a[] = "123";
    std::cout << str_to_int(a) << std::endl;

    return 0;
}