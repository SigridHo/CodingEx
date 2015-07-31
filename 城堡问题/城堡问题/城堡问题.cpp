#include <iostream>
#include <cstdio>
using namespace std;

int wall[60][60] = {0};
int used[60][60] = {0};
int number = 0;
int ma = 0;
int we[4] = {-1, 0, 1, 0};
int ns[4] = {0, -1, 0, 1};
int temp = 0;
void findout(int i, int j)
{
	used[i][j] = 1;
	temp++;
	for(int k = 0; k < 4; ++k)
	{
		if(wall[i][j] % 2 == 0 && used[i + ns[k]][j + we[k]] == 0)
		{
			findout(i + ns[k], j + we[k]);
		}
		wall[i][j] /= 2;
	}
}

int main() 
{
	int m, n;
	cin >> m >> n;
	for(int i = 0;i  < m; ++i)
		for(int j = 0; j < n; ++j)
			cin >> wall[i][j];
	for(int i = 0; i < m; ++i)
		for(int j = 0; j < n; ++j)
		{
			if(used[i][j] == 0)
			{
				temp = 0;
				number++;
				findout(i, j);
				if(temp > ma) ma = temp;
			}
		}
	cout << number << endl;
	cout << ma << endl;
	system("pause");
	return 0;
}