#include <iostream>
#include <string>
#include <cstring>
using namespace std;

char number[25] = {0};
int answer[25] = {0};
int mem = 0;
int num[25]= {0};
int m;
int k;
int cal(int dig, int times, int sum)
{
	if(m - dig == times) return sum;
	if(times == 0)
	{
		for(int i = dig; i < m; ++i)
		{
			sum *= 10;
			sum += num[i];
			
		}
		return sum;
	}
	else
	{
		int MIN = 10;
		int mindig[25][2] = {0};
		int comin = 0;
		for(int j = 0; j <= times; ++j, ++dig)
		{
			if(num[dig] < MIN) 
			{
				MIN = num[dig];
				comin = 0;
				mindig[comin][0] = dig;
				mindig[comin][1] = times - j;
				comin++;
			}
			else if(num[dig] == MIN)
			{
				mindig[comin][0] = dig;
				mindig[comin][1] = times - j;
				comin++;
			}
		}
		long long minanswer = 1000000000;
		for(int j = 0; j < comin; ++j)
		{
			int temp = cal(mindig[j][0] + 1,mindig[j][1], sum * 10 + MIN );
			if(temp < minanswer) minanswer = temp;
		}
		return minanswer;
	}
}
int main()
{
	int t;
	cin >> t;
	for(int i = 0; i < t; ++i)
	{
		memset(number, 0 , sizeof(number));
		memset(answer, 0, sizeof(answer));
		memset(num, 0, sizeof(num));
		mem = 0;
		cin >> number  >> k;
		m = strlen(number);
		for(int j = 0; j < m; ++j)
		{
			num[j] = number[j] - '0';
		}
		cout << cal(0, k, 0) << endl;
	}
	return 0;
} 