#include <iostream>
#include "date.h"
using namespace std;

int main()
{
    date        dtNow;
    date        dt2;
    int         ndays;
    

    cin >> dtNow >> ndays;
    dt2 = dtNow + ndays;
    cout << dt2 << endl;
    
	return 0;
}