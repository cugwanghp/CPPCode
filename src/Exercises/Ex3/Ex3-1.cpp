#include <iostream>

inline void swap(int& a, int& b)
{
    int t = a;
    a = b;
    b = t;
}

void pop_sort(int* pdata, int n)
{
    if (pdata==nullptr || n<2)
        return;

    for (int i=0; i<n-1; i++)
    {
        for (int j=0; j<n-i-1; j++)
        {
            if (pdata[j] > pdata[j+1])
            {
                swap(pdata[j], pdata[j+1]);
            }
        }
    }
}

int main()
{
    int a[] = {5, 4, 10, 8, 1, 2, 3};

    pop_sort(a, 7);
    
    for (const auto& elem : a)
        std::cout << elem << "\t";
    std::cout << std::endl;
    
    return 0;
}