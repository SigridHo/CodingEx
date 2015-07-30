#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;

int  number[650] = {0};
int gen(int a, int b)
{
	if(b % a == 0) return a;
	else return gen(b % a, a);
}
int main()
{
	while(1)
	{
		int n;
		cin >> n;
		if(n == 0) break;
		int temp ;
		for(int i = 0; i <n ;++i)
		{
			cin >> number[i];
		}
		sort(number, number + n);
		int sum = 0;
		for(int i = 0; i < n - 1; ++i)
			for(int j = i + 1; j < n; ++j)
			{
				if(gen(number[i], number[j]) == 1) sum++;
			}
			cout << sum << endl;
	}
	return 0;
}