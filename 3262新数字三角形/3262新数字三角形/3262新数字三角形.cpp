#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cstdlib>
#include <cmath>
#include <algorithm>
using namespace std;

int tri[110][110] = {0};
int mem[110][110] = {0};
int main()
{
	while(1)
	{
		int n;
		cin >> n;
		if(n == 0) break;
		memset(tri, 0, sizeof(tri));
		memset(mem, 0, sizeof(mem));
		for(int i = 0; i < n; ++i)
			for(int j = 0; j <= i; ++j)
				cin >> tri[i][j];
		for(int j = 0; j < n; ++j)
			mem[n - 1][j] = tri[n - 1][j];
		if(n > 1)
		{
			for(int i = n - 2; i >= 0; -- i)
			{
				for(int j = 0; j <= i; ++j)
				{
					mem[i][j] = max(mem[i + 1][j], mem[i + 1][j + 1]);
					mem[i][j] = max(tri[i][j], mem[i][j]);
				}
			}
		}
		int r, c;
		cin >> r >> c;
		cout << mem[r - 1][c - 1] << endl;
	}

	return 0;
}