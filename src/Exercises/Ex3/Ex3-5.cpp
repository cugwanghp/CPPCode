#include <iostream>

void transposeMatrix(auto* pMtx, int m, int n, auto* pTransMtx)
{
    for (int i=0; i<m; ++i)
    {
        for (int j=0; j<n; ++j)
        {
            pTransMtx[j*m+i] = pMtx[i*n+j];
        }
    }
}

int main()
{
    int a[4][3] = {1,2,3,4,5,6,7,8,9,10,11,12};
    int b[3][4];

    transposeMatrix(&a[0][0], 4, 3, &b[0][0]);

    for (int i=0; i<3; i++)
    {
        for (int j=0; j<4; j++)
        {
            std::cout << b[i][j] << "\t";
        }
        std::cout << std::endl;
    }

    return 0;
}