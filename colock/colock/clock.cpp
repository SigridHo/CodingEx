#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
using namespace std;

int init[10] = {0};
int mid[10] = {0};
int mov[10][5] = {{1,2,4,5},{1,2,3},{2,3,5,6},{1,4,7},{2,4,5,6,8},{3,6,9},{4,5,7,8},{7,8,9},{5,6,8,9}};
int change[10] = {0};
int answer[10] = {0};
int main() {
	for(int i = 1; i <= 9; ++i)
		cin >> init[i];
	int k = pow((double)4, (double)9);
	int MIN = 10000;
	for(int i = 0; i < k; ++i)
	{
		int temp = i;
		for(int j = 0; j < 9; ++ j)
		{
			change[j] =  temp % 4;
			temp /= 4;
		}
		for(int j = 1;j  <= 9; ++j)
			mid[j] = init[j];
		for(int j = 0; j < 9; ++j)
		{
			if(change[j] == 1)
			{
				for(int k = 0; k < 5; ++k)
				{
					mid[mov[j][k]]++;
				}	
			}
			if(change[j] == 2)
			{
				for(int k = 0; k < 5; ++k)
				{
					mid[mov[j][k]] += 2;
				}
			}
			if(change[j] == 3)
			{
				for(int k = 0; k < 5; ++k)
				{
					mid[mov[j][k]] += 3;
				}
			}
		}
		bool finish = true;
		for(int j = 1; j <= 9; ++ j)
		{
			if(mid[j] % 4 != 0)
			{
				finish = false;
				break;
			}
		}
		if(finish)
		{
			int sum = 0;
			for(int j = 0; j < 9; ++ j)
			{
				sum += change[j];
				if(sum > MIN) break;
			}
			if(MIN > sum) 
			{
				MIN = sum;
				for(int j = 0; j < 9; ++j)
				{
					answer[j] = change[j];
				}
			}
		}
	}
	for(int i = 0; i < 9;  ++i)
	{
		if(answer[i] != 0)
		{
			for(int j = 0; j < answer[i]; ++j)
				cout << i + 1 << ' ';
		}
	}
	system("pause");
	return 0;
}


