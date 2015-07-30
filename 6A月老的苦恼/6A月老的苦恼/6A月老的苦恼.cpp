#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int square[1010][1010] = {0};
int sumboy[1010] = {0};
int sumgirl[1010] = {0};
int minb[2] = {0};
int ming[2] = {0};
int main()
{
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i)
	{
		memset(square, 0, sizeof(square));
		memset(sumboy ,0, sizeof(sumboy));
		memset(sumgirl, 0, sizeof(sumgirl));
		memset(minb, 0, sizeof(minb));
		memset(ming, 0, sizeof(ming));
		int t;
		cin >> t;
		for(int j = 1; j <= t; ++j)
			for(int k = 1; k <= t; ++k)
			{
				cin >>square[j][k];
				sumboy[j]+= square[j][k];
			}
		for(int j = 1; j <=t; ++j)
			for(int k = 1; k <= t; ++k)
			{
				sumgirl[j] += square[k][j];
			}
		minb[0] = -1;
		ming[0] = -1;
		for(int j = 1; j <= t; ++j)
		{
			if(sumboy[j] > minb[0]) 
			{
				minb[0] = sumboy[j];
				minb[1] = j;
			}
			if(sumgirl[j] > ming[0]) 
			{
				ming[0] = sumgirl[j];
				ming[1] = j;
			}
		}
		cout << minb[1] << ' ' << ming[1] << endl;
	}
	return 0;
}