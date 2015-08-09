#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <string>
#include <queue>
using namespace std;

queue<int> list[10];
int seq[1010] = {0};
int main()
{
	int n;
	scanf("%d", &n);
	int max = -1;
	for(int i = 0; i < n; ++i)
	{
		scanf("%d", &seq[i]);
		if(seq[i] > max)
			max = seq[i];
	}
	int times = 0;
	while(max > 0)
	{
		times++;
		max /= 10;
	}
	int div = 1;
	for(int i = 1; i <= times ; ++i)
	{
		printf("Step%d.\n", i);
		for(int j = 0; j < n; ++j)
		{
			list[(seq[j] / div) % 10].push(seq[j]);
		}
		div*= 10;
		int cur = 0;
		for(int j = 0; j < 10; ++j)
		{
			printf("Queue%d:", j);
			if(!list[j].empty())
			{
				seq[cur] = list[j].front();
				printf("%d", seq[cur]);
				list[j].pop();
				cur++;
			}
			while(!list[j].empty())
			{
				seq[cur] = list[j].front();
				printf(" %d", seq[cur]);
				list[j].pop();
				cur++;
			}
			printf("\n");
		}
	}
	printf("%d", seq[0]);
	if(n > 1)
	{
		for(int i = 1; i < n; ++i)
			printf(" %d", seq[i]);
	}
	printf("\n");
	system("pause");
	return 0;
}