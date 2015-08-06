#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>

using namespace std;

int n = 0; 
char str[1000002] = {0};
int nextarr[1000002] = {0};

int main()
{
	for(int i = 1; ; ++i)
	{
		scanf("%d", &n);
		if(n == 0 ) break;
		memset(str, 0 , sizeof(str));
		memset(nextarr, 0, sizeof(nextarr));
		scanf("%s", str);
		printf("Test case #%d\n", i);
		nextarr[0] = -1;
		int len = strlen(str);
		int p = 0;  
		int k = -1;
		while (p < len) 
		{           
			while (k >= 0 && str[k] != str[p]) 
				k = nextarr[k];     
			p++;   
			k++; 
		    nextarr[p] = k;
		}  
		for(int l = 2; l  <= len; ++l)
		{
			if(l % (l - nextarr[l]) == 0)
			{
				int temp = l / (l - nextarr[l]);
				if(temp > 1) printf("%d %d\n", l , temp);
			}
		}
		printf("\n");
	}
	system("pause");
	return 0;
}