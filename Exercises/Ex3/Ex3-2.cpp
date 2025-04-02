#include <iostream>

int* bin_search(int* pdata, int n, int x)
{
    if (pdata==nullptr || n<1)
        return nullptr;

    int low = 0;
    int high = n;

    while(low < high)
    {
        int mid = (low+high)/2;

        if (pdata[mid] == x){
            return pdata+mid;
        }
        else if (x<pdata[mid]) {
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }

    return nullptr; 
}

int main()
{
    int a[20];
    for (int i=0; i<20; i++)
        a[i] = i+i*i+1;
    
    int     x;
    std::cout << "Input an integer for search: ";
    std::cin >> x;

    int*    pSearch = bin_search(a, 20, x);
    if (pSearch != nullptr)
        std::cout << x << " in pos " << pSearch-a+1 << std::endl;
    else
        std::cout << "not found.\n"; 
        
    return 0;
}