#include <iostream>
#include <cstring>
#include <string>
#include <cstdlib>
#include <cstdio>
using namespace std;

int n, m;
int arr[100010][16] = {0};
int question(int t)
{
	int sum = 0;
	for(int i = 0; i < n; ++i)
	{
		if(arr[i][t] == 1)
			sum++;
	}
	return sum;
}
void ntob(int a, int i)
{
	int c = 0;
	while(a > 0)
	{
		arr[i][c] = a % 2;
		a /= 2;
		c++;
	}
}
void Add(int j, int t)
{
	int temp[16] = {0};
	int c = 0;
	while(t > 0)
	{
		temp[c] = t % 2;
		t /= 2;
		c++;
	}
	for(int i = 0; i < 16; ++i)
	{
		arr[j][i] += temp[i];
		if(i != 15)
			arr[j][i + 1] += arr[j][i] / 2;
		arr[j][i] %= 2;
	}
}
int main()
{

	scanf("%d%d", &n, &m);
	for(int i = 0; i < n; ++i)
	{
		int a;
		scanf("%d", &a);
		ntob(a, i);
	}
	for(int i = 0; i < m; ++i)
	{
		char ins[5] = {0};
		scanf("%s", ins);
		if(ins[0] == 'Q')
		{
			int t;
			scanf("%d", &t);
			printf("%d\n", question(t));
		}
		else if(ins[0] == 'C')
		{
			int t;
			scanf("%d", &t);
			for(int  j = 0; j < n; ++j)
				Add(j, t);
		}
		else i--;
	}
	system("pause");
	return 0;
}