#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;

int answer[100000] = {0};
int digit = 0;
void multi(int number)
{
	for(int i = 0; i < digit; ++i)
	{
		answer[i] *= number;
	}
	for(int i = 0; i < digit; ++i)
	{
		if(answer[i] > 9)
		{
			answer[i + 1] += answer[i] / 10;
			answer[i] %= 10;
		}
	}
	while(answer[digit] > 0)
	{
		digit++;
		if(answer[digit - 1] > 9)
		{
			answer[digit] += answer[digit - 1] / 10;
			answer[digit - 1] %= 10;
		}
	}
}
int main()
{
	int n;
	cin >> n;
	if(n == 0 || n == 1) 
	{
		for(int i = 0; i < 49; ++i)
			cout << '0';
		cout << '1' << endl;
	}
	else
	{
		answer[0] = 1;
		digit = 1;
		for(int i = 2; i <= n; ++i)
		{
			multi(i);
		}
		if(digit % 50 != 0)
		{
			for(int i = 0; i < 50 - (digit % 50); ++i)
				cout << '0';
		}
		int i;
		for(i = digit - 1; i > digit - 1 - (digit % 50); --i)
			cout << answer[i];
		cout << endl;
		int j = 1;
		for(; i >= 0; --i,++j)
		{
			cout << answer[i];
			if(j % 50 == 0) cout << endl;
		}
	}
	system("pause");
	return 0;
}