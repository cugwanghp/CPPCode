#include <iostream>
#include <iomanip>

int main()
{
	// 1-n 总和
		int	n;
		int sum = 0;
		std::cin >> n;	
		
		int	i = 1;
		while (true) {
				sum = sum + i;
				i++;
				if (i > 10) break;
		}

		for (; i <= n; i++) {
				sum = sum + i;
		}
		// i>n, i=n+1

		do {

		} while (i<=n);

		return 0;
}