#include <iostream>
using namespace std;


int main()
{
	int t;
	cin >> t;
	for(int i = 0; i < t; ++i)
	{
		int n, m;
		cin >> n >> m;
		int parent[110] = {0};
		int left[110] = {0};
		int right[110] = {0};
		for(int j = 0; j < n; ++j)
		{
			int p, l ,r;
			cin >> p >> l >> r;
			if(l > -1)
			{
				parent[l] = p;
			}
			if(r > -1)
			{
				parent[r] = p;
			}
			left[p] = l;
			right[p] = r;
		}
		for(int j = 0; j < m; ++j)
		{
			int type;
			cin >> type;
			if(type == 1)
			{
				int x, y;
				cin >> x >> y;
				int temp, temp2;
				temp = parent[x];
				temp2 = parent[y];
				parent[x] = parent[y];
				parent[y] = temp;
				bool leftx = false;
				bool lefty = false;
				if(left[temp] == x) leftx = true;
				if(left[temp2] == y) lefty = true;
				if(leftx) left[temp] = y;
				else right[temp] = y;
				if(lefty) left[temp2] = x;
				else right[temp2] = y;
			}
			if(type == 2)
			{
				int node;
				cin >> node;
				while(left[node] != -1)
				{
					node = left[node];
				}
				cout << node << endl;
			}
		}
	}
	system("pause");
	return 0;
}