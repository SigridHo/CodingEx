#include <iostream>
using namespace std;

int calculate(int pay, int days)
{
	if(days <= pay) return days * pay;
	else return pay * pay + calculate(pay + 1, days - pay);
}
int main()
{
	while(1)
	{
		int n;
		cin >> n;
		if(n == 0) break;
		int step = 0;
		step = calculate(1, n);
		cout << n << ' ' <<  step << endl;
	}
	return 0;
}