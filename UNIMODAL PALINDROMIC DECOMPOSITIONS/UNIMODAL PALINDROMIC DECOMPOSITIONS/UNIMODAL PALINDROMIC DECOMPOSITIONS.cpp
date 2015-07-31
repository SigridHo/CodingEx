#include <iostream>
using namespace std;

long long table[10000][10000] = {0};
long long calculate(int begin, int n)
{
	if(n == 0)
	{
		table[begin][n] = 1;
		return 1;
	}
	if(begin == 0)
	{
		table[begin][n] = 1;
		return 1;
	}
	if(n < begin * 2) 
	{
		table[begin][n] = 0;
		return 0;
	}
	if(table[begin][n] != 0) return table[begin][n] ;
	long long sum = 0;
	long long temp = n - begin * 2;
	for(int i = begin; i <= n / 2; ++i)
	{
		if(temp >= 2 * i) sum += calculate(i, n - begin * 2);
	}
	if(temp >= begin || temp == 0) sum++;
	table[begin][n] = sum;
	return sum;
}

int main() 
{
	for(int i = 0; i < 10000; ++i)
		table[0][i] = 1;
	while(1)
	{
		int n;
		cin >> n;
		if(n == 0) break;
		long long sum = 0;
		for(int i = 0; i < n; ++i)
			sum += calculate(i, n);
		cout << n << ' ' << sum << endl;
	}
	return 0;
}