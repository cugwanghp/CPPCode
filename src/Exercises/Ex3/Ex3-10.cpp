#include <iostream>
#include <cassert>

//将copy_ints函数的代码放在这里。
void copy_ints(const int* psrc, int n, int* pdst)
{
    for (int i=0; i<n; ++i)
    {
        *pdst++ = *psrc++;
    }
}

int main ()
{
    const int src[4]={1,2,3,4};
    int dst[4]={0,0,0,0};
    
    copy_ints(src,4,dst);
    
    for (const auto& elem : dst)
        std::cout << elem << "\t";
    std::cout << std::endl;
    
//    assert (!memcmp(src, dst, sizeof(src)));
}