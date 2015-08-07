#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <vector>
using namespace std;

const int prime = 100007;
vector<int> HashTable[prime];
int snow[100010][6] = {0};
bool cmp(int a, int b)
{
	bool result = true;
	for(int i = 0; i < 6; ++i)
	{
		result = true;
		for(int j = 0; j < 6; ++j)
		{
			if(snow[a][j] != snow[b][(i + j) % 6])
			{
				result = false;
				break;
			}
		}
		if(result) return true;
	}
	for(int i = 0; i < 6; ++i)
	{
		result = true;
		for(int j = 0; j < 6; ++j)
		{
			if(snow[a][j] != snow[b][(6 + i - j) % 6])
			{
				result = false;
				break;
			}
		}
		if(result) return true;
	}
	return false;
}
void search()
{
	for(int i = 0; i < prime; ++i)
	{
		if(HashTable[i].size() > 1)
		{
			
			for(int j = 0; j < HashTable[i].size() - 1; ++j)
			{
				for(int k = j + 1; k < HashTable[i].size(); ++k)
				{
					if(cmp(HashTable[i][j], HashTable[i][k]))
					{
						printf("Twin snowflakes found.\n");
						return;
					}
				}
			}
		}
	}
	printf("No two snowflakes are alike.\n");
}
int main()
{
	int n;
	scanf("%d", &n);
	for(int i =  0; i < n; ++i)
	{
		int sum = 0;
		for(int j = 0; j < 6; ++j)
		{
			scanf("%d", &snow[i][j]);
			sum = (sum + (snow[i][j] % prime)) % prime;
		}
		HashTable[sum].push_back(i);
	}
	search();
	system("pause");
	return 0;
}