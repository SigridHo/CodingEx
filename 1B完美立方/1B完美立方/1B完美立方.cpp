#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;

int triple[110] = {0};
int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 0; i <= n; ++i)
	{
		triple[i] = i * i * i;
	}
	int a, b, c, d;
	for(a = 6; a <= n; ++ a)
	{
		for(b = 2; b <= n; ++b)
		{
			for(c = b; c <= n; ++c)
			{
				for(d = c; d <= n; ++ d)
				{
					if(triple[a] == triple[b] + triple[c] + triple[d]) 
					{
						printf("Cube = %d, Triple = (%d,%d,%d)\n", a, b, c, d);
					}
				}
			}
		}

	}
	system("pause");
	return 0;

}