#include <iostream>
using namespace std;

int sum[110][110] = {0};
int line[110] = {0};
int main()
{
	int n;
	cin >> n;
	int temp; 
	int rowsum = 0;
	for(int i = 1; i <= n ;++i)
	{
		for(int j = 1; j <= n ;++j)
		{
			cin >> temp;
			sum[i][j] = temp;
			if(j > 0) sum[i][j] += sum[i][j - 1];
		}
	}
	int sum1 = 0;
	int sum2 = 0;
	int MAX = -10000000;
	int MIN = 0;
	int answer = -100000000;
	for(int i = 0; i < n; ++i)
		for(int j = i + 1; j <= n; ++j)
		{
			MAX = -100000000;
			MIN = 0;
			sum1 = 0;
			sum2 = 0;
			for(int k = 0; k <= n; ++k)
			{
				sum1 += sum[k][i];
				sum2 += sum[k][j];
				line[k] = sum2 - sum1;
			}
			int MIN = 0;
			int gap = 0;
			for(int m = 0; m <= n; ++m)
			{
				if(line[m] < MIN)
					MIN = line[m];
				if(line[m] - MIN > gap)
					gap = line[m] - MIN;
			}
			if(answer < gap) answer = gap;
		}
	cout << answer << endl;
	system("pause");
	return 0;
}