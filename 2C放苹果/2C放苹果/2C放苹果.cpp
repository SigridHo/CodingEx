#include <iostream>
using namespace std;

int mem[20][20] = {0};
int cal(int m, int n)
{
	if(mem[m][n] != 0) return mem[m][n];
	if(n == 1) 
	{
		mem[m][n] = 1;
		return 1;
	}
	if(n == 0)
	{
		mem[m][n] = 0;
		return 0;
	}
	if(m == 1 || m == 0) 
	{
		mem[m][n] = 1;
		return 1;
	}
	if(m < n)
	{
		mem[m][n] = cal(m, m);
		return mem[m][n];
	}
	if(m >= n)
	{	
		mem[m][n] = cal(m, n - 1) + cal(m - n, n);
		return mem[m][n];
	}
}

int main()
{
	int t;
	cin >> t;
	for(int i = 0; i < t; ++i)
	{
		int m, n;
		cin >> m >> n;
		cout << cal(m, n) << endl;
	}
	return 0;
}
