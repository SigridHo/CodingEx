#include <iostream>
#include <cstring>
using namespace std;

char square[102][102] = {0};
char table[102][102][102][102] = {0};
int n;
int ma = 0;
void count()
{
	for(int i = n; i >= 1; --i)
		for(int j = n; j >= 1; -- j)
		{
			for(int k = 1; k <= n - i + 1; ++k)
			{
				for(int m = 1; m <= n - j + 1; ++m)
				{
					table[i][j][k][m] = square[i][j] + table[i + 1][j][k -1][m] + table[i][j + 1][1][m -1];
					if(table[i][j][k][m] > ma) ma = table[i][j][k][m];
				}
			}
		}
}
int main()
{
	cin >> n;
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= n; ++j)
		{
			cin >> square[i][j];
			table[i][j][1][1] = square[i][j];
			if(square[i][j] > ma) ma = square[i][j];
		}
	count();
	cout << ma << endl;
	return 0;
}