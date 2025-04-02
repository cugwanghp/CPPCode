#include <iostream>

// -1 - not found, others - max value index based 0
int findMax(int* pdata, int n)
{
    // not found
    if (pdata==nullptr || n<1)
        return -1;
    
    int     maxIndex = 0;
    for (int i=1; i<n; ++i)
    {
        if (pdata[i] > pdata[maxIndex])
        {
            maxIndex = i;
        }
    }

    return maxIndex;
}

int main()
{
    int     n;
    std::cin >> n;

    int*    pdata = new int[n];
    for (int i=0; i<n; i++)
        std::cin >> pdata[i];

    int     indexMax = findMax(pdata, n);
    if (indexMax >= 0){
        std::cout << "The max value is " << pdata[indexMax];
        std::cout << " at " << indexMax+1 << std::endl;
    }

    return 0;    
}