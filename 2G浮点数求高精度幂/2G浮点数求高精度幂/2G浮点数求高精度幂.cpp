#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
#include <cstdlib>
using namespace std;

int answer[300] = {0};
int number[6] = {0};
int num = 0;
double num1 = 0;
int point = 0;
int digit = 0;
void multi()
{
	for(int i = 0; i < digit; ++i)
	{
		answer[i] *= num;
	}
	for(int i = 0; i < digit; ++i)
	{
		if(answer[i] > 9)
		{
			answer[i + 1] += answer[i] / 10;
			answer[i] %= 10;
		}
	}
	while(answer[digit] > 9)
	{
		digit++;
		answer[digit] += answer[digit - 1] / 10;
		answer[digit - 1] %= 10;
	}
	while(answer[digit] == 0)
	{
		digit--;
	}
	digit++;
}
int main() {
	char s[6] = {0};
	int times;
	while(cin >> s >> times)
	{
		memset(answer, 0, sizeof(answer));
		memset(number, 0, sizeof(number));
		point = 0;
		num = 0;
		num1 = 0;
		digit = 0;
		for(int i = 5;  i >= 0; --i)
		{ 
			if(s[i] == '.')
			{
				point = 5 - i;
			}
			else 
			{
				number[digit] = s[i] - '0';
				answer[digit] = s[i] - '0';
				digit++;
			}
		}
		int zero = 0;
		for(zero = 0; ; zero++)
		{
			if(number[zero] != 0) break;
		}
		point -= zero;
		num1 = atof(s);
		for(int i = 0; i < point; ++i)
			num1 *= 10;
		if(((int)(num1 * 10)) % 10 > 5) num = num1 + 1;
		else num = num1;
		if(times == 1) 
		{
			int z1= 0 , z2 = 0;
			for(; z1 < 6; ++z1)
			{
				if(s[z1] != '0') break;
			}
			for(z2 = 5; z2 >= 0; -- z2)
			{
				if(s[z2] != '0') break;
			}
			if(s[z2] != '.')
			{
				for(int i = z1; i <= z2; ++i)
					cout << s[i];
				cout << endl;
			}
			else 
			{
				for(int i = z1; i < z2; ++i)
					cout << s[i];
				cout << endl;
			}
		}
		else
		{
			for(int i = 2; i <= times; ++i)
			{
				multi();
			}
			
			int zero1 = 0;
			for(zero1 = 0; ; ++ zero1)
			{
				if(answer[zero1] != 0) break;
			}
			point *= times;
			point += zero1;
			if(digit <= point)
			{
				cout << '.';
				if(digit != point)
				{
					for(int i = 0; i < point - digit; ++i)
						cout << '0';
				}
				for(int i = digit - 1; i >= zero1; --i)
					cout << answer[i];
				cout << endl;
			}
			else
			{
				for(int i = digit - 1; i >= point; --i)
					cout << answer[i];
				if(point - 1 >= zero) 
				{
					cout << '.';
					for(int i = point - 1; i >= zero1; --i)
						cout << answer[i];
				}
				cout << endl;
			}
		}
	}
	return 0;
}