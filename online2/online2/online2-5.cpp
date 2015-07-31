#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
using namespace std;

int main() 
{
	while(1)
	{
		int number;
		cin >> number;
		char queue[6] = {0};
		cin >> queue;
		int diff = 1000000;
		int times = 0;
		if(number == 0 && strlen(queue) == 1 && queue[0] == '0') break;
		if(atof(queue) == number) {cout << number << ' ' << number << endl; continue;}
		int sum = 0;
		int len = strlen(queue);
		for(int i = 0; i < len; ++i)
		{
			sum += queue[i] - '0';
			if(sum > number) break;
		}
		if(sum < number && number - sum < diff) 
		{
			diff = number - sum;
			times = 1;
		}
		if(len > 1)
		{
			for(int i = 0; i < len - 1; ++i)
			{
				sum = 0;
				for(int j = 0; j < len ; ++j)
				{
					if(j == i)
					{
						sum += (queue[j] - '0' ) * 10;
					}
					else sum += queue[j] - '0';
					if(sum > number) break;
				}
				if(sum < number && number - sum < diff) 
				{
					diff = number - sum;
					times = 1;
				}
				if(sum < number && number - sum == diff)
				{
					times++;
				}
			}
		}
		if(len > 2 && number > 100)
		{
			for(int i = 0; i < len - 2; ++i)
			{
				sum = 0;
				for(int j = 0; j < len ; ++j)
				{
					if(j == i)
					{
						sum += (queue[j] - '0' ) * 100;
					}
					else if(j - 1 == i) sum += (queue[j] - '0') * 10;
					else sum += queue[j] - '0';
					if(sum > number) break;
				}
				if(sum < number && number - sum < diff) 
				{
					diff = number - sum;
					times = 1;
				}
				if(sum < number && number - sum == diff)
				{
					times++;
				}
			}
		}
		if(len > 3 && number > 1000)
		{
			for(int i = 0; i < len - 3; ++i)
			{
				sum = 0;
				for(int j = 0; j < len ; ++j)
				{
					if(j == i)
					{
						sum += (queue[j] - '0' ) * 1000;
					}
					else if(j - 1 == i) sum += (queue[j] - '0') * 100;
					else if(j - 2 == i) sum += (queue[j] - '0') * 10;
					else sum += queue[j] - '0';
					if(sum > number) break;
				}
				if(sum < number && number - sum < diff) 
				{
					diff = number - sum;
					times = 1;
				}
				if(sum < number && number - sum == diff)
				{
					times++;
				}
			}
		}
		if(len > 4 && number > 10000)
		{
			for(int i = 0; i < len - 4; ++i)
			{
				sum = 0;
				for(int j = 0; j < len ; ++j)
				{
					if(j == i)
					{
						sum += (queue[j] - '0' ) * 10000;
					}
					else if(j - 1 == i) sum += (queue[j] - '0') * 1000;
					else if(j - 2 == i) sum += (queue[j] - '0') * 100;
					else if(j - 3 == i) sum += (queue[j] - '0') * 10;
					else sum += queue[j] - '0';
					if(sum > number) break;
				}
				if(sum < number && number - sum < diff) 
				{
					diff = number - sum;
					times = 1;
				}
				if(sum < number && number - sum == diff)
				{
					times++;
				}
			}
		}
		if(len > 5 && number > 100000)
		{
			sum = atof(queue);
			if(sum < number && number - sum < diff) 
			{
				diff = number - sum;
				times = 1;
			}
			if(sum < number && number - sum == diff)
			{
				times++;
			}
		}
		if()
	}
	return 0;
}