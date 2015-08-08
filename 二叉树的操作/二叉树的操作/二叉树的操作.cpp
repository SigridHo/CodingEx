#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	int t;
	scanf("%d", &t);
	for(int i = 0; i < t; ++i)
	{
		int parent[110] = {0};
		int left[110] = {0};
		int right[110] = {0};
		bool isleft[110] = {0};
		int n, m;
		scanf("%d%d", &n, &m);
		for(int j = 0; j < n; ++j)
		{
			int p, l, r;
			scanf("%d%d%d", &p, &l, &r);
			if(l > -1)
			{
				left[p] = l;
				parent[l] = p;
				isleft[l] = true;
			}
			if(r > -1)
			{
				right[p] = r;
				parent[r] = p;
			}
		}
		for(int j = 0; j < m; ++j)
		{
			int type;
			scanf("%d", &type);
			if(type == 1)
			{
				int x, y;
				scanf("%d%d", &x, &y);
				int temp = parent[x];
				parent[x] = parent[y];
				parent[y] = temp;
				if(isleft[x] && isleft[y])
				{
					left[parent[x]] = x;
					left[parent[y]] = y;
				}
				else if(!isleft[x] && !isleft[y])
				{
					right[parent[x]] = x;
					right[parent[y]] = y;
 				}
				else if(!isleft[x] && isleft[y])
				{
					right[parent[y]] = y;
					left[parent[x]] = x;
					isleft[y] = false;
					isleft[x] = true;
				}
				else if(isleft[x] && !isleft[y])
				{
					right[parent[x]] = x;
					left[parent[y]] = y;
					isleft[x] = false;
					isleft[y] = true;
				}

			}
			else if(type == 2)
			{
				int x;
				scanf("%d", &x);
				while(left[x] != 0)
					x = left[x];
				printf("%d\n", x);
			}
		}
	}
	system("pause");
	return 0;
}