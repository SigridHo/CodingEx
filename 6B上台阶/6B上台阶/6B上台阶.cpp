#include <iostream>
#include <cstring>
#include <string>
using namespace std;

int mem[110] = {0};
int cal(int n)
{
	if(mem[n] != 0) return mem[n];
	else
	{
		int sum = 0;
		sum = cal(n - 1) + cal(n - 2) + cal(n - 3);
		mem[n] = sum;
		return mem[n];
	}
}

int main()
{
	mem[0] = 0;
	mem[1] = 1;
	mem[2] = 2;
	mem[3] = 4;
	while(1)
	{
		int n;
		cin >> n;
		if(n == 0) break;
		cout << cal(n) << endl;
	}
	return 0;
}
