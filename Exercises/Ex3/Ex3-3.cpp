#include <iostream>

// 交换两个数
inline void swap(auto& a, auto& b)
{
    auto    t = a;
    a = b;
    b = t;
}

// 倒置数组元素
void reverse(int* pdata, int n)
{
    if (pdata == nullptr)
        return;

    for (int i=0; i<n/2; ++i)
        swap(pdata[i], pdata[n-1-i]);
}

int main()
{
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    reverse(a, 9);

    for (const auto& elem : a)
        std::cout << elem << "\t";
    std::cout << std::endl;

    return 0;
}