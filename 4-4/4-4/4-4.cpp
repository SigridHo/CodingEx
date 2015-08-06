#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
using namespace std;

char number[1000] = {0};
char digit[3][10] = {"million", "thousand", "hundred"};
char standard[32][15] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety", "hundred", "thousand", "million"};
int main()
{
	while(cin.getline(number, 1000, '\n'))
	{
		int len = strlen(number);
		if(len == 0) break;
		int a = 0, b = 0, c = 0;
		bool  thousand = false, million = false, negative = false;
		int integer[100] = {0};
		char temp[20] = {0};
		int sign = 0;
		for(int i = 0; i < len; ++i)
		{
			memset(temp, 0 ,sizeof(temp));
			int j = 0;
			while(number[i] != ' ' && number[i] != 0)
			{
				temp[j] = number[i];
				j++;
				i++;
			}
			int k = 0;
			if(strcmp(temp, "negative") == 0)
			{
				negative = true;
				continue;
			}
			for(k = 0; k < 30; ++k)
			{
				if(strcmp(standard[k] , temp) == 0)
					break;
			}
			if(k > 20 && k < 28)
				k = 20 + (k - 20) * 10;
			else if(k == 28)
				k = 100;
			else if(k == 29)
				k = 1000;
			else if(k == 30)
				k = 1000000;
			integer[sign] = k;
			sign++;
		}
		int p = sign - 1;
		for( ; p >= 0; --p)
		{
			if(integer[p] == 100)
			{
				a += integer[p - 1] * 100;
				p--;
			}
			else if(integer[p] == 1000)
			{
				thousand = true;
				p--;
				break;
			}
			else if(integer[p] == 1000000)
			{
				million = true;
				p--;
				break;
			}
			else a += integer[p];
		}
		if(thousand)
		{
			for(; p >= 0; --p)
			{
				if(integer[p] == 100)
				{
					b += integer[p - 1] * 100;
					p--;
				}
				else if (integer[p] == 1000000)
				{
					million = true;
					p--;
					break;
				}
				else b += integer[p];
			}
		}
		if(million)
		{
			for(; p >= 0; --p)
			{
				if(integer[p] == 100)
				{
					c += integer[p - 1] * 100;
					p--;
				}
				else c += integer[p];
			}
		}
		int sum = a + 1000 * b + 1000000 * c;
		if(negative) sum = 0 - sum;
		cout << sum << endl;
		memset(number, 0 ,sizeof(number));
	}
	return 0;
}

