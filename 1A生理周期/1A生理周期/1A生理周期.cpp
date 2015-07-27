#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
	for(int k = 1; ; ++k)
	{
		int p, e, i, d;
		scanf("%d%d%d%d", &p, &e, &i, &d);
		if(p == -1 && e == -1 && i == -1 && d == -1) break;
		int j = 0;
		for(j = 1; ; ++j)
		{
			int temp = d + j;
			if((temp - p) % 23 == 0 && (temp - e) % 28 == 0 && (temp - i) % 33 == 0)
				break;
		}
		printf("Case %d: the next triple peak occurs in %d days.\n", k, j);
	}
	return 0;
}