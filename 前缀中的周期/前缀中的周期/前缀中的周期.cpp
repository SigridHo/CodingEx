#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <cstring>
using namespace std;

int Next[1000002] = {0};
char str[1000002] = {0};
int main()
{
	for(int i = 1; ; ++i)
	{
		int len;
		memset(Next, 0, sizeof(Next));
		memset(str, 0, sizeof(str));
		scanf("%d", &len);
		if(len == 0)
			break;
		scanf("%s", str);
		int p = 0;
		int k = -1;
		Next[p] = k;
		printf("Test case #%d\n", i);
		while(p < len)
		{
			while(k >= 0 && str[p] != str[k])
				k = Next[k];
			p++;
			k++;
			Next[p] = k;
		}
		for(int a = 2; a <= len; ++a)
		{
			if(a % (a - Next[a]) == 0)
			{
				int temp = a / (a - Next[a]);
				if(temp > 1) printf("%d %d\n", a, temp);
			}
		}
		printf("\n");
	}
	return 0;
}