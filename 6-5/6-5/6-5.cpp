#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;


int Father[50010] = {0};
int relation[50010] = {0};

int FindRoot(int x)
{
	if(x != Father[x])
	{
		int fx = FindRoot(Father[x]);
		relation[x] = (relation[x] + relation[Father[x]]) % 3;
		Father[x] = fx;
	}
	return Father[x];
}
bool Union(int op, int x, int y)
{
	int fx = FindRoot(x);
	int fy = FindRoot(y);
	if(fx == fy)
	{
		if((relation[y] - relation[x] + 3) % 3 == op)
			return false;
		else return true;
	}
	Father[fy] = fx;
	relation[fy] = (relation[x] +op - relation[y] + 3) % 3;
	return false;
}
int main()
{
	int n, k;
	scanf("%d %d", &n, &k);
	for(int i = 1; i <= n; ++i)
		Father[i] = i;
	int sum = 0;
	int op, x, y;
	for(int i = 0; i < k; ++i)
	{
		scanf("%d %d %d", &op, &x, &y);
		if(x > n || y > n || (x == y && op == 2))
			sum++;
		else if(Union(op - 1, x, y))
			sum++;
	}
	printf("%d\n", sum);
	system("pause");
	return 0;
}

