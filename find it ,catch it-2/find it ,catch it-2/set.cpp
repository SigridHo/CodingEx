#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
using namespace std;
const int Size = 100005;
struct Node
{
	int diff;
	int rank;
	int father;
};
Node gang[Size];
void init(int n)
{
	for(int i = 1; i <= n; ++i)
	{
		gang[i].diff = 0;
		gang[i].father = i;
		gang[i].rank = 0;
	}
}
int Find(int a)
{
	if(gang[a].father != a)
	{
		gang[a].father = Find(gang[a].father);
	}
	return gang[a].father;
}
void Union(int a, int b)
{
	if(gang[a].rank > gang[b].rank )
	{
		gang[b].father = a;
	}
	else
	{
		gang[a].father = b;
		if(gang[a].rank == gang[b].rank )
			gang[b].rank++;
	}
}
int main()
{
	int t;
	scanf("%d", &t);
	for(int i = 0; i < t; ++i)
	{
		int n, m;
		scanf("%d%d",&n,&m);
		init(n);
		for(int j = 0; j < m; ++j)
		{
			char instr[2];
			scanf("%s", instr);
			int a, b;
			scanf("%d%d", &a, &b);
			int p = Find(a);
			int q = Find(b);
			if(instr[0] == 'D')
			{
				if(gang[p].diff != 0)
					Union(Find(gang[p].diff), q);
				if(gang[q].diff != 0)
					Union(Find(gang[q].diff), p);
				if(gang[p].diff == 0)
					gang[p].diff = q;
				if(gang[q].diff == 0)
					gang[q].diff = p;
			}
			else if(instr[0] == 'A')
			{
				if(p == q)
					printf("In the same gang.\n");
				else
				{
					if(Find(gang[p].diff) == q)
						printf("In different gangs.\n");
					else
						printf("Not sure yet.\n");
				}
			}
			else j--;
		}
	}
	system("pause");
	return 0;
}



