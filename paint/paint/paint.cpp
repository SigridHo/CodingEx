#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
using namespace std;

char init[18][18] = {0};
int mid[18][18] = {0};
int answer[18][18] = {0};
int a[18] = {0};
int MIN = 10000;
int binary[18] = {0};

void change(int n);
void firststate(int n)
{
	for(int i = 0; i < binary[n]; ++ i)
	{
		int temp = i;
		memset(answer, 0, sizeof(answer));
		memset(mid, 0, sizeof(answer));
		for(int j = 1; j <= n; ++j)
		{
			a[j] = temp & 1;
			answer[1][j] = a[j];
			temp = temp >> 1;
		}
		for(int j = 1; j <= n; ++j)
			for(int k = 1; k <= n; ++k)
			{
				if(init[j][k] == 'w') mid[j][k] = 0;
				else mid[j][k] = 1;
			}
		change(n);
	}
}

void change(int n)
{
	int number  = 0;
	for(int i = 1; i <= n; ++i)
	{
		for(int j = 1; j <= n; ++j)
		{
			if(answer[i][j] == 1)
			{
				mid[i - 1][j] = mid[i - 1][j] ^ 1;
				mid[i + 1][j] = mid[i + 1][j] ^ 1;
				mid[i][j] = mid[i][j] ^ 1;
				mid[i][j - 1] = mid[i][j - 1] ^ 1;
				mid[i][j + 1] = mid[i][j + 1] ^ 1;
				number++;
				if(number > MIN) return;
			}
		}
		for(int j = 1; j <= n; ++j)
		{
			if(mid[i][j] == 0) answer[i + 1][j] = 1;
		}
	}
	for(int i = 1; i <= n; ++i)
	{
		if(mid[n][i] == 0) return;
	}
	if(number < MIN) MIN = number;
}


int main() {
	int t;
	cin >> t;
	int temp = 1;
	binary[0] = 1;
	for(int i = 1 ; i < 18; ++i)
	{
		temp *= 2;
		binary[i] = temp;
		
	}
	for(int i = 0; i < t; ++i)
	{
		int n;
		cin >> n;
		memset(init, 0, sizeof(init));
		for(int j = 1; j <= n; ++j)
			for(int k = 1; k <= n; ++k)
				cin >> init[j][k];
		memset(answer, 0, sizeof(answer));
		firststate(n);	
		if(MIN == 10000) cout << "inf" << endl;
		else cout << MIN << endl;
		MIN = 10000;
	}
	system("pause");
	return 0;
}
