#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
#include <cstdio>
using namespace std;

int n;
typedef long long LL;
LL c;
const int MAX = 25;
const int up = 1;
const int down = 0;
LL method[MAX][MAX][2] = {0};
int answer[MAX] = {0};
void init(int number)
{
	method[1][1][up] = 1;
	method[1][1][down] = 1;
	for(int len = 2; len <= number; ++len)
	{
		for(int i = 1; i <= len; ++i)
		{
			for(int x = i; x < len; ++x)
			{
				method[i][len][up] += method[x][len - 1][down];
			}
			for(int x = 1; x < i; ++x)
			{
				method[i][len][down] += method[x][len - 1][up];
			}
		}
	}
}
void solve()
{
	int tn = n;
	int flag = -1, cur = 0;
	LL sum = 0LL;
	for(int i = 1; i <= n; ++i)
	{
		if(sum + method[i][n][up] + method[i][n][down] >= c)
		{
			answer[1] = i;
			cur = i;
			c -= sum;
			break;
		}
		sum+=(method[i][n][up]+method[i][n][down]);
	}
	if(c > method[cur][n][down])
	{
		c -= method[cur][n][down];
		flag = up;
	}
	else flag = down;
	int len = 2;
	--n;
	while(n > 0)
	{
		if(flag == up)
		{
			for(int i = cur; i <= n; ++i)
			{
				if(method[i][n][down] >= c)
				{
					cur = i;
					answer[len++] = cur;
					
					break;
				}
				c -= method[i][n][down];
			}
		}
		else
		{
			for(int i = 1; i < cur; ++i)
			{
				if(method[i][n][up] >= c)
				{
					cur = i;
					answer[len++] = i;
				
					break;
				}
				c -= method[i][n][up];
			}
		}
		--n;
		flag = 1 - flag;
	}
	int vis[MAX] = {0};
	for(int i = 1; i <= tn; ++i)
	{
		for(int j = 1; j <= tn; ++j)
		{
			if(vis[j] == 0)
			{
				answer[i]--;
				if(answer[i] == 0)
				{
					cout << j;
					if(i == tn) cout << endl;
					else cout << ' ';
					vis[j] = 1;
					break;
				}
			}
		}
	}
	 
}
int main()
{
	int t;
	scanf("%d", &t);
	init(20);
	for(int i = 0; i < t; ++i)
	{
		cin >> n >> c;
		memset(answer, 0, sizeof(answer));
		solve();
	}
	system("pause");
	return 0;
}