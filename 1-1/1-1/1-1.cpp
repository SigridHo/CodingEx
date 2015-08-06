#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int mem[10000][10000] = {0};
int cal(int a, int b)
{
	if(mem[a][b] != 0) return mem[a][b];
	if(b == 0) return 0;
	if(b == 1)
	{
		mem[a][b] = 1;
		return 1;
	}
	if(a == 1)
	{
		mem[a][b] = 1;
		return 1;
	}
	if(b > a)
	{
		mem[a][b] = cal(a, a);
		return mem[a][b];
	}
	if(b == a) 
	{
		mem[a][b] = 1 + cal(a, a - 1);
		return mem[a][b];
	}
	if(b < a)
	{
		mem[a][b] = cal(a, b - 1) + cal(a - b, b);
		return mem[a][b];
	}
}
int main()
{
	int m, n;
	cin >> m >> n;
	cout << cal(m , n) << endl;
	system("pause");
	return 0;
}