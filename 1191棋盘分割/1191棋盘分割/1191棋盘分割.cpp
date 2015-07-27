#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
using namespace std;

int s[9][9] = {0};
int sum[9][9] = {0};
int rec[18][9][9][9][9] = {0};
int calsum(int x1, int y1, int x2, int y2)
{
	return sum[x2][y2] + sum[x1- 1][y1 - 1] - sum[x1 -1][y2] - sum[x2][y1 -1];
}
int fun(int n, int x1, int y1, int x2, int y2)
{
	int MIN = 100000000;
	if(rec[n][x1][y1][x2][y2] != -1) return rec[n][x1][y1][x2][y2];
	//if(x2 - x1 + y2 - y1 < n - 1 )return 1000000000;
	if(n == 1) 
	{
		int t = calsum(x1, y1, x2, y2);
		rec[n][x1][y1][x2][y2] = t * t;
		return t * t;
	}
	else
	{
		for(int i = x1; i < x2; ++i)
		{
			int c = calsum(x1, y1, i, y2);
			int e = calsum(i + 1, y1, x2, y2);
			int t = min(c * c + fun(n - 1, i + 1, y1, x2, y2), e * e + fun(n - 1, x1, y1, i, y2));
			MIN = min(MIN , t);
		}
		for(int j = y1 ; j < y2 ; ++j)
		{
			int c = calsum(x1, y1, x2, j);
			int e = calsum(x1, j + 1, x2, y2);
			int t = min(c * c + fun(n - 1, x1, j + 1, x2, y2), e * e + fun(n - 1, x1, y1, x2, j));
			MIN = min (MIN , t);
		}
		rec[n][x1][y1][x2][y2] = MIN;
		return MIN;
	}

}

int main()
{
	int n;
	scanf("%d", &n);
	int rowsum = 0;
	memset(rec, -1, sizeof(rec));
	for(int i = 1; i <= 8; ++i)
		for(int j = 1, rowsum = 0; j <= 8; ++j)
		{
			scanf("%d", &s[i][j]);
			rowsum += s[i][j];
			sum[i][j] = sum[i - 1][j] + rowsum;
		}
	int step = fun(n, 1, 1, 8, 8);
	double result = n * step - sum[8][8] * sum[8][8];
	result = sqrt(result / (n * n));
	printf("%.3lf\n", result);
	system("pause");
	return 0;
}

