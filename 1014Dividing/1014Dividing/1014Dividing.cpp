#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
#include <algorithm>
using namespace std;

int number[7] = {0};
int method[7][3000] = {0};
int main()
{
	for(int i = 1; ; ++i)
	{
		memset(method, 0, sizeof(method));
		memset(number, 0, sizeof(number));
		bool allzero = true;
		int value = 0;
		for(int j = 0; j < 6; ++j)
		{
			scanf("%d", &number[j]);
			number[j] %= 100;
			if(number[j]) allzero = false;
			value += number[j] * (j + 1);
		}
		if(allzero) break;
		printf("Collection #%d:\n", i);
		if(value % 2 != 0) 
		{
			printf("Can't be divided.\n\n");
			continue;
		}
		for(int j = 0 ; j <= 6; ++j)
			method[j][0] = 1;
		for(int j = 5; j >= 0; --j)
		{
			for(int k = 0; k <= value / 2; ++ k)
			{
				int sum = 0;
				for(int m = 0; m <= number[j]; ++m)
				{
					if(k >= m * (j + 1))
					{
						sum += method[j + 1][k - m * (j + 1)];
					}
					else break;
				}
				method[j][k] = sum;
			}
		}
		int temp = method[0][value / 2];
		if(temp > 0) printf("Can be divided.\n\n");
		else printf("Can't be divided.\n\n");
		
	}
	return 0;
}