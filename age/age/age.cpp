#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
#include <algorithm>
using namespace std;

int stick[70] = {0};
bool findout(int length, int n, int times)
{
	int check[70] = {0};
	int init[70] = {0};
	memset(init, length, sizeof(init));
	int step = 0;
	for(int i = 0; i < times; ++i)
	{
		init[i] -= stick[i];
		if(binary_search(stick + times, stick + n, init[i]) 
		check[i] = 1;
	}
	for(int i = times; i < n; ++i)
	{
		if(check[i] == 0)
		{
			if(stick[i] <
		}
	}
}
int main()
{
	while(1)
	{
		int n;
		cin >> n;
		if(n == 0) break;
		memset(stick, 0, sizeof(stick));
		int max = 0;
		int sum = 0;
		for(int i = 0; i < n; ++i)
		{
			cin >> stick[i];
			if(stick[i] > max) max = stick[i];
			sum += stick[i];
		}
		int length = max;
		int times = 0;
		sort(stick, stick + n, greater<int>());
		for(;length <= sum; ++length)
		{
			if(sum % length != 0) continue;
			else times = sum / length;
			if(findout(length, n, times))
				cout << length << endl;
		}
	}
	return 0;
}


